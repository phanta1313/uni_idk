import zipfile
import xml.etree.ElementTree as ET

def read_xlsx_with_zip(file_path):
    with zipfile.ZipFile(file_path, "r") as z:
        # Читаем sharedStrings.xml (общие строки)
        shared_strings = []
        if "xl/sharedStrings.xml" in z.namelist():
            with z.open("xl/sharedStrings.xml") as f:
                tree = ET.parse(f)
                root = tree.getroot()
                shared_strings = [t.text for t in root.findall(".//{http://schemas.openxmlformats.org/spreadsheetml/2006/main}t")]

        # Читаем sheet1.xml (данные листа)
        with z.open("xl/worksheets/sheet1.xml") as f:
            tree = ET.parse(f)
            root = tree.getroot()
            
            # Пространство имен
            ns = {"main": "http://schemas.openxmlformats.org/spreadsheetml/2006/main"}
            
            # Читаем все ячейки
            rows = []
            for row in root.findall(".//main:row", ns):
                row_data = []
                for cell in row.findall("main:c", ns):
                    cell_type = cell.get("t")  # Тип ячейки (s - строка, иначе число)
                    value = cell.find("main:v", ns)
                    if value is not None:
                        if cell_type == "s":
                            row_data.append(shared_strings[int(value.text)])  # Индекс строки
                        else:
                            row_data.append(value.text)  # Число
                rows.append(row_data)

    return rows

# Читаем Excel-файл
data = read_xlsx_with_zip("example.xlsx")

# Вывод данных
for row in data:
    print(row)
