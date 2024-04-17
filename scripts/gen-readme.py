import os
import json
from pathlib import Path


def get_title() -> str:
    md = "# MONITORIA DE EDA1\n\n"

    return md


def get_syllabus() -> str:
    md = """## :book: Ementa\n
<div>
    <details>
        <summary>Ponteiros e alocação dinâmica de memória.</summary>
    </details>
    <details>
        <summary>Princípios da análise de algoritmos</summary>
        <ul>
            <li>Complexidade computacional.</li>
            <li>Análise assintótica: notação Big-O.</li>
        </ul>
    </details>
    <details>
        <summary>Recursão</summary>
        <ul>
            <li>Algoritmos recursivos</li>
            <li>Método da divisão e conquista</li>
        </ul>
    </details>
    <details>
        <summary>Estrutura de dados</summary>
        <ul>
            <li>Elementares (lineares):</li>
                <ul>
                    <li>Arrays e listas</li>
                    <li>Listas encadeadas.</li>
                </ul>
            <li>Tipos abstratos de dados</li>
                <ul>
                    <li>Filas</li>
                    <li>Pilhas</li>
                    <li>Árvores binárias</li>
                </ul>
        </ul>
    </details>
    <details>
        <summary>Algoritmos de ordenação</summary>
        <ul>
            <li>Métodos elementares:</li>
                <ul>
                    <li>Selection Sort</li>
                    <li>Insertion Sort</li>
                    <li>Bubble Sort</li>
                </ul>
            <li>Quicksort</li>
            <li>Mergesort</li>
            <li>Filas de prioridades e heapsort</li>
            <li>Radix sorting</li>
        </ul>
    </details>
    <details>
        <summary>Algoritmos de busca</summary>
        <ul>
            <li>Busca sequencial</li>
            <li>Busca binária</li>
            <li>Árvores de busca binária</li>
        </ul>
    </details>
</div>\n
"""

    return md


def valid_section(section: Path) -> bool:
    return section.is_dir()


def get_section_name(section: str) -> str:
    return section.replace("-", " ").title()


def valid_file(file: Path) -> bool:
    return file.is_file() and file.name.endswith((".c", ".h"))


def get_file_text_name(list_file: str) -> str:
    name, _ = list_file.split(".")
    name = name.replace("-", " ")
    name = name.replace("_", " ")
    return name.title()


def get_relative_path(file: Path) -> str:
    return str(file).split("..")[1]


def get_files_from_dir(dir: str) -> list:
    cur_path = Path(__file__).parent / ".." / dir
    output = dict()

    if not valid_section(cur_path):
        return output

    for section in os.listdir(cur_path):
        if valid_section(cur_path / section):
            output[section] = dict()
            for cur_section in os.listdir(cur_path / section):
                if cur_section != "code":
                    continue

                for section_day in os.listdir(cur_path / section / cur_section):
                    if valid_section(cur_path / section / cur_section / section_day):
                        output[section][section_day] = list()
                        for list_file in os.listdir(cur_path / section / cur_section / section_day):
                            output[section][section_day].append(
                                {
                                    "file": list_file,
                                    "name": get_file_text_name(list_file),
                                    "path": get_relative_path(cur_path / section / cur_section / section_day / list_file),
                                }
                            )

        elif valid_file(cur_path / section):
            if 'libs' not in output:
                output['libs'] = list()
            output['libs'].append(
                {
                    "name": get_file_text_name(section),
                    "path": get_relative_path(cur_path / section),
                }
            )

    return output


def check_annotations(dir: str, semester: str, date: str) -> str:
    cur_path = Path(__file__).parent / ".." / dir
    for file in os.listdir(cur_path / semester / 'docs' / date):
        if file.split('.') == ['annotations', 'pdf']:
            return True
    return False


def get_recording(dir: str, semester: str, date: str) -> str:
    cur_path = Path(__file__).parent / ".." / dir
    for file in os.listdir(cur_path / semester / 'docs' / date):
        if file.split('.') == ['recording', 'json']:
            with open(cur_path / semester / 'docs' / date / file) as file:
                json_object = json.load(file)
                return json_object['link']


def get_semesters_md() -> str:
    output = get_files_from_dir('base')
    md = "## :computer: Monitorias\n\n<div>\n"
    for section in output:
        md += f"    <details>\n        <summary>{section}</summary>\n"
        md += "        <ul>\n"
        for day_month in output[section]:
            md += f"            <li>{'/'.join(day_month.split('-')[::-1])}</li>\n            <ul>\n"
            for exercise in output[section][day_month]:
                md += f"                <li>Exercício: <a target='_self' href='https://github.com/unbytes/eda1-monitoria/tree/main{exercise['path']}'>{exercise['name']}</a> + <a target='_self' href='https://github.com/unbytes/eda1-monitoria/tree/main/base/{section}/docs/{day_month}/{exercise['file'].split('.')[0]}.pdf'>PDF</a></li>\n"

            if check_annotations('base', section, day_month):
                md += f"                <li>Anotações da aula - <a target='_self' href='https://github.com/unbytes/eda1-monitoria/tree/main/base/{section}/docs/{day_month}/annotations.pdf'>PDF</a></li>\n"

            recording_link = get_recording('base', section, day_month)
            if recording_link:
                md += f"                <li>Gravação da aula - <a target='_self' href='{recording_link}'>Drive</a></li>\n"
            md += "            </ul>\n"
        md += "        </ul>\n    </details>\n"

    md += "</div>\n\n"

    return md


def get_libs() -> str:
    md = "## :package: Pacotes (Algoritmos)\n\n"

    output = get_files_from_dir('libs')
    if 'libs' in output:
        for section in output['libs']:
            md += (f"- [{section['name']}](https://github.com/unbytes/eda1-monitoria/blob/main{section['path']})\n")
        md += "\n"

    return md


def get_teacher() -> str:
    md = """## :man_teacher: Professora\n
- [Rose Yuri Shimizu](https://sigaa.unb.br/sigaa/public/docente/portal.jsf?siape=1276557)\n
"""

    return md


def get_references() -> str:
    md = """## :books: Referências\n
- [Plano de Ensino](https://fga.rysh.com.br/eda1/)
- Robert Sedgewick Algorithms in C, Addison Wesley, 3nd ed.
- [Algorithms, 4th Edition - Robert Sedgewick e Kevin Wayne](https://algs4.cs.princeton.edu/home/)
- [Prof. Bruno Ribas](https://www.brunoribas.com.br/)
- [Prof. Paulo Feofiloff](https://www.ime.usp.br/~pf/algoritmos/index.html#C-language)
- Thomas H. Cormen et al Algoritmos - Teoria e Prática, Elsevier, 3nd ed.\n
"""

    return md


def get_observation() -> str:
    md = """## :dart: Observações\n
Para compilar os códigos que utilizam as bibliotecas customizadas da pasta `libs` é necessário utilizar o seguinte comando:

```bash
mkdir "listas/XX/code/output"
gcc -I libs -o "listas/XX/code/output/YY" "listas/XX/code/YY.c"

"./listas/XX/code/output/YY"
```

Em que `XX` é o número da lista e `YY` é o número do exercício."""

    return md


def build_md() -> str:
    md = ""
    md += get_title()
    md += get_syllabus()
    md += get_semesters_md()
    md += get_libs()
    md += get_teacher()
    md += get_references()
    md += get_observation()
    return md


print(build_md())
