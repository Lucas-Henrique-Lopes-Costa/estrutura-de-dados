import re
from bs4 import BeautifulSoup


def generate_cpp_files(html_file_path):
    # Ler o conteúdo do arquivo HTML
    with open(html_file_path, "r", encoding="utf-8") as file:
        html_content = file.read()

    # Usar BeautifulSoup para analisar o conteúdo HTML
    soup = BeautifulSoup(html_content, "html.parser")

    # Encontrar todos os contêineres de questões
    question_containers = soup.find_all("div", class_="problem-try-ct")

    for container in question_containers:
        question_name = container.find("h3").text.strip()
        description_box = container.find("div", class_="description-display-box")
        if description_box:
            question_description = description_box.get_text(separator="\n", strip=True)
        else:
            question_description = "Descrição não encontrada."

        # Formatar o nome do arquivo com base no nome da questão
        filename = re.sub(r"[^\w\s]", "", question_name)
        filename = " ".join(filename.split()[1:2])
        filename = filename.lower() + ".cpp"

        # Gerar conteúdo para o arquivo .cpp
        cpp_content = f"""/*
{question_name}
{question_description}
*/

#include <iostream>
using namespace std;

int main() {{
    // Seu código aqui
    return 0;
}}
"""

        # Criar e escrever no arquivo .cpp
        with open(filename, "w", encoding="utf-8") as cpp_file:
            cpp_file.write(cpp_content)
        print(f"Arquivo {filename} gerado com sucesso.")


if __name__ == "__main__":
    # Definir o caminho do arquivo HTML
    html_file_path = "codigo.html"
    generate_cpp_files(html_file_path)
