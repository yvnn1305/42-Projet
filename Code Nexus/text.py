class CSVExportPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        result = []
        for element in data:
            rang, values = element
            result.append(values)
        output = ",".join(result)
        print("CSV Output:")
        print(output)

class JSONExportPlugin:
    def process_output(self, data: list[tuple[int, str]]) -> None:
        result = []
        for element in data:
            rang, values = element
            tup = f'"{rang}": "{values}"'
            result.append(tup)
        output = ",".join(result)
        print("JSON Output:")
        print(f"{{{output}}}")

if __name__ == "__main__":
    data = [(0, "3.14"), (1, "-1"), (2, "2.71")]
    plugin = CSVExportPlugin()
    plugin.process_output(data)
    plugin1 = JSONExportPlugin()
    plugin1.process_output(data)