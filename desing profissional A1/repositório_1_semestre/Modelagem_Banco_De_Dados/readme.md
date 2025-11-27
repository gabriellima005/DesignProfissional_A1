# 📝 Modelagem de Banco de Dados

## 💡 Sobre a Disciplina

A disciplina de **Modelagem de Banco de Dados** é a base para o desenvolvimento de qualquer sistema robusto. Ela ensina as técnicas e metodologias para **projetar a estrutura de dados** de uma aplicação de forma íntegra, eficiente e consistente.

> **🎯 Objetivo Central:** Transformar requisitos de negócio em um *blueprint* (projeto) de banco de dados que possa ser implementado em SGBDs (PostgreSQL, MySQL, etc.).

---

## 🪜 Estágios da Modelagem (O Processo)

O projeto de um banco de dados relacional é dividido em três etapas sequenciais:

| Estágio | Foco Principal | Artefato / Resultado |
| :--- | :--- | :--- |
| **1. Conceitual** | **O QUE?** Requisitos de Negócio. | **Diagrama de Entidade-Relacionamento (DER)**. Nível mais abstrato. |
| **2. Lógico** | **COMO?** Estrutura do SGBD Relacional. | **Normalização** (1FN, 2FN, 3FN). Define chaves e cardinalidades. |
| **3. Físico** | **ONDE?** Tecnologia Específica. | **Scripts SQL** de criação (`CREATE TABLE`, `INDEX`). Otimização para o SGBD. |

---

## 🔑 Conceitos e Ferramentas Chave

### Linguagens e Técnicas

* **DER (Diagrama de Entidade-Relacionamento):** Representação gráfica dos dados (Entidades, Atributos e Relacionamentos).
* **Normalização:** Processo de refino do modelo lógico para eliminar redundâncias e garantir a integridade dos dados.
* **SQL (Structured Query Language):** Linguagem padrão usada para gerenciar, consultar e manipular dados no banco.

### Elementos Fundamentais

* **Entidade:** Objeto do mundo real que deve ser armazenado (Ex: `Cliente`, `Produto`).
* **Atributo:** Característica da entidade (Ex: `nome`, `email`, `preço`).
* **Chave Primária (PK):** Identificador único de uma linha na tabela.
* **Chave Estrangeira (FK):** Campo usado para criar o relacionamento entre duas tabelas.

---

## 📂 Estrutura de Arquivos

Nosso repositório da disciplina é organizado de acordo com as etapas do processo:
