/*
== Obtendo dados de várias tabelas

> Join (Junção)
    - Use uma junção para consultar dados a partir de uma ou mais tabelas
    - Criar uma condição de junção na cláusula ON.
    - Prefixar o nome da coluna com o nome da tabela quando o mesmo nome da coluna aparecer em 
        mais de uma tabela

-- Exemplo de uso de JOIN para consultar dados de duas tabelas
SELECT      <tabela1.coluna>, <tabela2.coluna>      -- Seleciona colunas específicas das tabelas
FROM        <tabela1> JOIN <tabela2>                -- Define as tabelas que serão unidas
ON          <tabela1.coluna1> = <tabela2.coluna2>;  -- Define a condição de junção
*/

USE Exercicio_2;

/* Criando uma nova tabela a partir de outra ===================== */

-- Cria uma nova tabela chamada 'empregado' a partir de uma cópia dos dados da tabela 'scott.emp'
CREATE TABLE empregado AS (SELECT * FROM scott.emp); -- Note que aqui estamos copiando a tabela de outra database

-- Seleciona e exibe todos os dados da tabela 'empregado' para verificar se a cópia foi feita corretamente
SELECT * FROM empregado;

-- Cria uma nova tabela chamada 'departamentos' a partir de uma cópia dos dados da tabela 'scott.dept'
CREATE TABLE departamentos AS (SELECT * FROM scott.dept);

-- Seleciona e exibe todos os dados da tabela 'departamentos' para verificar se a cópia foi feita corretamente
SELECT * FROM departamentos;

-- Seleção de duas tabelas (cláusula JOIN) =========================

-- Seleciona colunas específicas das tabelas empregados e departamentos
SELECT 
    empregados.empno,        -- Número do empregado
    empregados.ename,        -- Nome do empregado
    empregados.deptno,       -- Número do departamentos do empregado
    departamentos.deptno,    -- Número do departamentos (da tabela departamentos)
    departamentos.loc        -- Localização do departamentos
FROM 
    empregados               -- Tabela principal: empregados
JOIN 
    departamentos             -- Junção com a tabela departamentos
ON 
    empregados.deptno = departamentos.deptno;  -- Condição de junção: deptno deve ser igual em ambas as tabelas

/* 
Podemos simplificar nossa pesquisa usandop aliases:
*/

SELECT 
    e.empno,        -- Número do empregado
    e.ename,        -- Nome do empregado
    e.deptno,       -- Número do departamento do empregado
    d.deptno,       -- Número do departamento (da tabela departamentos)
    d.loc           -- Localização do departamento
FROM 
    empregados e    -- Tabela principal: empregados (alias 'e') >> definimos o ALIAS AQUI
JOIN 
    departamentos d -- Junção com a tabela departamentos (alias 'd')
ON 
    e.deptno = d.deptno;  -- Condição de junção: deptno deve ser igual em ambas as tabelas