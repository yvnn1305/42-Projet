from typing import Any, Protocol
from abc import ABC, abstractmethod


class DataProcessor(ABC):
    def __init__(self) -> None:
        self._total: int = 0
        self._rang: int = 0
        self._stock: list[str] = []

    @abstractmethod
    def validate(self, data: Any) -> bool:
        ...

    @abstractmethod
    def ingest(self, data: Any) -> None:
        ...

    def output(self) -> tuple[int, str]:
        last = self._stock.pop(0)
        rang = self._rang
        self._rang += 1
        return (rang, last)

    def remaining(self) -> int:
        return len(self._stock)

    def get_total_processed(self) -> int:
        return (self._total)


class NumericProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, list):
            return all(isinstance(element, (int, float)) for element in data)
        else:
            return isinstance(data, (int, float))

    def ingest(self, data: int | float | list[int | float]) -> None:
        if not self.validate(data):
            raise ValueError("Improper numeric data")
        if isinstance(data, list):
            for element in data:
                self._stock.append(str(element))
                self._total += 1
        else:
            self._stock.append(str(data))
            self._total += 1


class TextProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, list):
            return all(isinstance(element, str) for element in data)
        return isinstance(data, str)

    def ingest(self, data: str | list[str]) -> None:
        if not self.validate(data):
            raise ValueError("Improper text data")
        if isinstance(data, list):
            for element in data:
                self._stock.append(element)
                self._total += 1
        else:
            self._stock.append(data)
            self._total += 1


class LogProcessor(DataProcessor):
    def validate(self, data: Any) -> bool:
        if isinstance(data, list):
            return all(isinstance(element, dict) for element in data)
        return isinstance(data, dict)

    def ingest(self, data: dict[str, str] | list[dict[str, str]]) -> None:
        if not self.validate(data):
            raise ValueError("Improper log data")
        if isinstance(data, list):
            for element in data:
                transform = f"{element['log_level']}: {element['log_message']}"
                self._stock.append(transform)
                self._total += 1
        else:
            transform = f"{data['log_level']}: {data['log_message']}"
            self._stock.append(transform)
            self._total += 1


class ExportPlugin(Protocol):
    def process_output(self, data: list[tuple[int, str]]) -> None:
        ...


class DataStream:
    def __init__(self) -> None:
        self._processor: list[DataProcessor] = []

    def register_processor(self, proc: DataProcessor) -> None:
        self._processor.append(proc)

    def process_stream(self, stream: list[Any]) -> None:
        for element in stream:
            processed = False

            for processor in self._processor:
                if processor.validate(element):
                    processor.ingest(element)
                    processed = True
                    break
            if not processed:
                print("DataStream error - Can’t process element in stream: "
                      f"{element}")

    def print_processors_stats(self) -> None:
        print("== DataStream statistics ==")

        if len(self._processor) == 0:
            print("No processor found, no data")
            return

        for processor in self._processor:
            name = processor.__class__.__name__
            name = name.replace("Processor", " Processor")
            print(f"{name}: total "
                  f"{processor.get_total_processed()} items processed, "
                  f"remaining {processor.remaining()} on processor")

    def output_pipeline(self, nb: int, plugin: ExportPlugin) -> None:
        for processor in self._processor:
            liste = []
            for _ in range(nb):
                if processor.remaining() == 0:
                    break
                tup = processor.output()
                liste.append(tup)
            plugin.process_output(liste)


class CSVExportPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        result = []
        for element in data:
            _, values = element
            result.append(values)
        output = ",".join(result)
        print("CSV Output:")
        print(output)


class JSONExportPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        result = []
        for element in data:
            rang, values = element
            tup = f'"item_{rang}": "{values}"'
            result.append(tup)
        output = ", ".join(result)
        print("JSON Output:")
        print(f"{{{output}}}")


if __name__ == "__main__":
    print("=== Code Nexus - Data Pipeline ===")
    print()

    print("Initialize Data Stream...")
    print()

    stream = DataStream()
    stream.print_processors_stats()
    print()

    print("Registering Processors")
    for proc in [NumericProcessor(), TextProcessor(), LogProcessor()]:
        stream.register_processor(proc)
    print()

    batch = [
        "Hello world",
        [3.14, -1, 2.71],
        [{'log_level': 'WARNING', 'log_message':
          'Telnet access! Use ssh instead'},
         {'log_level': 'INFO', 'log_message': 'User wil is connected'}],
        42,
        ["Hi", "five"],
    ]
    print(f"Send first batch of data on stream: {batch}")
    print()

    stream.process_stream(batch)
    stream.print_processors_stats()
    print()

    print("Send 3 processed data from each processor"
          " to a CSV plugin:")
    stream.output_pipeline(3, CSVExportPlugin())
    print()

    stream.print_processors_stats()
    print()

    batch1 = [
        21,
        ["I love AI", "LLMs are wonderful", "Stay healthy"],
        [{'log_level': 'ERROR', 'log_message': '500 server crash'},
         {'log_level': 'NOTICE', 'log_message': 'Certificate expires'
          ' in 10 days'}],
        [32, 42, 64, 84, 128, 168],
        "World hello",
    ]
    print(f"Send another batch of data: {batch1}")
    print()

    stream.process_stream(batch1)
    stream.print_processors_stats()
    print()

    print("Send 5 processed data from each processor to a JSON plugin:")
    stream.output_pipeline(5, JSONExportPlugin())
    print()

    stream.print_processors_stats()
