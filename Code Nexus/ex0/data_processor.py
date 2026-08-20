from typing import Any
from abc import ABC, abstractmethod

class DataProcessor(ABC):
    def __init__(self) -> None:
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
        else:
            self._stock.append(str(data))



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
        else:
            self._stock.append(data)

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
        else:
            transformed = f"{data['log_level']}: {data['log_message']}"
            self._stock.append(transformed)
        

if __name__ == "__main__":
    print("=== Code Nexus - Data Processor ===")
    print()

    print("Testing Numeric Processor...")
    test1 = NumericProcessor()
    print(f"Trying to validate input '42': {test1.validate(42)}")
    print(f"Trying to validate input 'Hello': {test1.validate("Hello")}")
    print("Test invalid ingestion of string 'foo' without prior validation:")
    try:
        test1.ingest("foo")
    except ValueError as e:
        print(f"Got exception: {e}")
    data = [1, 2, 3, 4, 5]
    print(f"Processing data: {data}")
    test1.ingest(data)
    print("Extracting 3 values...")
    for i in range(3):
        a, b = test1.output()
        print(f"Numeric value {a}: {b}")
    print()

    print("Testing Text Processor...")
    test2 = TextProcessor()
    print(f"Trying to validate input '42': {test2.validate(42)}")
    Strings = ["Hello", "Nexus", "World"]
    print(f"Processing data: {Strings}")
    test2.ingest(Strings)
    print("Extracting 1 value...")
    a, b = test2.output()
    print(f"Text value {a}: {b}")
    print()

    print("Testing Log Processor...")
    test3 = LogProcessor()
    print(f"Trying to validate input 'Hello': {test3.validate("Hello")}")
    Dict = [
        {'log_level': 'NOTICE', 'log_message': 'Connection to server'},
        {'log_level': 'ERROR', 'log_message': 'Unauthorized access!!'},
    ]
    print(f"Processing data: {Dict}")
    test3.ingest(Dict)
    print("Extracting 2 values...")
    for i in range(2):
        a, b = test3.output()
        print(f"Log entry {a}: {b}")