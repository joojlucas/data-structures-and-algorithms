-english:
# Final Project - Data Structures and Algorithms (Event Management System)
This repository contains the source code for the final project of the Data Structures and Algorithms (AED1) discipline. The project is a console-based event management system developed in C, allowing both organizers to manage events and participants to register and interact with events.

## Features
The program offers two main user roles with distinct functionalities:

## Organizer Menu
- **Insert a new event:** Allows organizers to add new events with details such as ID, title, category, description, dates, times, location, ticket price, and available tickets.

- **Search events:** Find and display event details by ID.

- **Update event data:** Modify existing event information.

- **Remove an event:** Delete an event from the system.

## Participant Menu
- **Register as a participant:** Create a new participant profile with ID, name, email, and phone number.

- **Consult registration:** View participant's registered details.

- **Update registration data:** Modify existing participant information.

- **Buy a ticket:** Purchase a ticket for a specific event, which also updates the available tickets for that event.

- **Cancel a ticket:** Cancel a previously purchased ticket, returning it to the event's available tickets.

- **Search for a ticket:** View details of purchased tickets.

- **Search for an event:** Find and display event details by ID.

- **Remove registration:** Delete a participant's profile from the system.

## Covered Topics and Relation to the Discipline (AED1)
This project serves as a practical application of core concepts taught in a Data Structures and Algorithms discipline, particularly focusing on:

**Structures (Structs):** Extensive use of struct (e.g., Evento, Participante) to define custom data types for representing complex entities with multiple attributes. This is fundamental for organizing heterogeneous data.

**File Handling (File I/O):** Persistent storage of Evento and Participante data in binary files (eventos and participantes). This involves operations like fopen, fread, fwrite, rewind, remove, and rename to perform CRUD (Create, Read, Update, Delete) operations on records. This demonstrates how data can be maintained beyond program execution, a basic form of database management.

**Arrays:** Used to store a fixed number of ticket IDs (ingressos[20]) within the Participante struct, representing the events a participant has tickets for.

**Functions and Modularity:** The code is well-structured with distinct functions for each operation (e.g., insereEvento, compraIngresso, atualizaCadastro, removeEvento, imprimeMenu, menu_Organizador, menu_Participante). This promotes code reusability, readability, and maintainability, essential principles for larger projects.

**Control Flow (Loops and Conditionals):** Extensive use of while loops for iterating through file records and for loops for processing arrays of tickets. switch statements manage menu navigation, and if conditions handle data validation, search results, and update/deletion logic.

**Basic Data Management Operations (CRUD):** The system implements fundamental CRUD operations for both events and participants, showcasing how data can be effectively managed in a file-based system. The update and delete operations involve creating temporary files (dummy/aux) to rewrite data, a common pattern in file-based record management.

**Input/Output Operations:** Standard input (scanf, getchar) and output (printf) functions are used for user interaction, demonstrating basic console application development.

This project effectively integrates these data structures and algorithmic approaches (like sequential file traversal for search/update/delete) to build a functional system, reflecting a solid understanding of the AED1 curriculum.

-portuguese:

# Trabalho Final - Estruturas de Dados e Algoritmos (Sistema de Gerenciamento de Eventos)
Este repositório contém o código-fonte do trabalho final da disciplina de Estruturas de Dados e Algoritmos (AED1). O projeto é um sistema de gerenciamento de eventos baseado em console, desenvolvido em C, que permite tanto a organizadores gerenciarem eventos quanto a participantes se registrarem e interagirem com os eventos.

## Funcionalidades
O programa oferece dois papéis de usuário principais com funcionalidades distintas:

## Menu do Organizador
Inserir um novo evento: Permite aos organizadores adicionar novos eventos com detalhes como ID, título, categoria, descrição, datas, horários, local, preço do ingresso e ingressos disponíveis.

- **Pesquisar eventos: Encontra e exibe os detalhes de um evento pelo ID.

- **Atualizar dados de um evento: Modifica informações existentes de um evento.

- **Remover um evento: Exclui um evento do sistema.

## Menu do Participante
- **Cadastrar-se como participante:** Cria um novo perfil de participante com ID, nome, e-mail e número de telefone.

- **Consultar cadastro:** Visualiza os detalhes de registro do participante.

- **Atualizar dados de cadastro:** Modifica informações existentes do cadastro do participante.

- **Comprar ingresso:** Compra um ingresso para um evento específico, o que também atualiza a quantidade de ingressos disponíveis para esse evento.

- **Cancelar ingresso:** Cancela um ingresso comprado anteriormente, retornando-o aos ingressos disponíveis do evento.

- **Pesquisar um ingresso:** Visualiza os detalhes dos ingressos comprados.

- **Pesquisar algum evento:** Encontra e exibe os detalhes de um evento pelo ID.

- **Remover cadastro:** Exclui o perfil de um participante do sistema.

## Conteúdos Abordados e Relação com a Disciplina (AED1)
Este projeto serve como uma aplicação prática de conceitos centrais ensinados na disciplina de Estruturas de Dados e Algoritmos, focando particularmente em:

- **Estruturas (Structs):** Uso extensivo de struct (ex: Evento, Participante) para definir tipos de dados personalizados que representam entidades complexas com múltiplos atributos. Isso é fundamental para organizar dados heterogêneos.

- **Manipulação de Arquivos (File I/O):** Armazenamento persistente de dados de Evento e Participante em arquivos binários (eventos e participantes). Isso envolve operações como fopen, fread, fwrite, rewind, remove e rename para realizar operações CRUD (Criar, Ler, Atualizar, Excluir) em registros. Isso demonstra como os dados podem ser mantidos além da execução do programa, uma forma básica de gerenciamento de banco de dados.

- **Arrays:** Utilizados para armazenar um número fixo de IDs de ingressos (ingressos[20]) dentro da struct Participante, representando os eventos para os quais um participante possui ingressos.

- **Funções e Modularidade:** O código é bem estruturado com funções distintas para cada operação (ex: insereEvento, compraIngresso, atualizaCadastro, removeEvento, imprimeMenu, menu_Organizador, menu_Participante). Isso promove a reutilização de código, legibilidade e manutenibilidade, princípios essenciais para projetos maiores.

- **Controle de Fluxo (Laços e Condicionais):** Uso extensivo de laços while para iterar sobre registros de arquivos e laços for para processar arrays de ingressos. Declarações switch gerenciam a navegação do menu, e condições if lidam com validação de dados, resultados de pesquisa e lógica de atualização/exclusão.

- **Operações Básicas de Gerenciamento de Dados (CRUD):** O sistema implementa operações CRUD fundamentais para eventos e participantes, mostrando como os dados podem ser efetivamente gerenciados em um sistema baseado em arquivos. As operações de atualização e exclusão envolvem a criação de arquivos temporários (dummy/aux) para reescrever os dados, um padrão comum no gerenciamento de registros baseado em arquivos.

- **Operações de Entrada/Saída:** Funções padrão de entrada (scanf, getchar) e saída (printf) são usadas para interação com o usuário, demonstrando o desenvolvimento básico de aplicações de console.

Este projeto integra efetivamente essas estruturas de dados e abordagens algorítmicas (como a travessia sequencial de arquivos para busca/atualização/exclusão) para construir um sistema funcional, refletindo uma sólida compreensão da ementa da disciplina de AED1.
