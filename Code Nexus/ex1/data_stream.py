from typing import Any
from abc import ABC, abstractmethod

class DataProcessor(ABC):
    def __init__(self) -> None:
        self._total: int = 0
        self._rang: int = 0
        self._stock: list[str] = []
    @abstractmethod
    def validate(self, data: Any) -> bool:
       pass 

    @abstractmethod
    def ingest(self, data: Any) -> None:
        pass

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
                transformed = f"{element['log_level']}: {element['log_message']}"
                self._stock.append(transformed)
                self._total += 1
        else:
            transformed = f"{data['log_level']}: {data['log_message']}"
            self._stock.append(transformed)
            self._total += 1


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
                      f"{element}"
                      )

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



def main():
    print("=== Code Nexus - Data Stream ===")
    print()

    print("Initialize Data Stream...")
    stream = DataStream()
    stream.print_processors_stats()
    print()
    
    print("Registering Numeric Processor")
    numeric = NumericProcessor()
    stream.register_processor(numeric)
    print()

    input = [
        "Hello world",
        [3.14, -1, 2.71],
        [{'log_level': 'WARNING', 'log_message': 'Telnet access! Use ssh instead'},
        {'log_level': 'INFO', 'log_message': 'User wil is connected'}],
        42,
        ["Hi", "five"],
    ]
    print(f"Send first batch of data on stream: {input}")
    stream.process_stream(input)
    stream.print_processors_stats()
    print()

    print("Registering other data processors")
    text = TextProcessor()
    stream.register_processor(text)
    log = LogProcessor()
    stream.register_processor(log)
    print("Send the same batch again")
    stream.process_stream(input)
    stream.print_processors_stats()
    print()

    print("Consume some elements from the data processors: Numeric 3, Text 2, Log 1")
    for i in range(3):
        numeric.output()
    for i in range(2):
        text.output()
    log.output()
    stream.print_processors_stats()
if __name__ == "__main__":
    main()
