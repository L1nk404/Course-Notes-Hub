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

/*
> Junções Idênticas

Uma junção idêntica (ou self-join) ocorre quando uma tabela é unida a ela mesma para 
comparar ou relacionar dados dentro da mesma tabela. Essa técnica é útil quando você 
precisa:
- Comparar registros da mesma tabela (ex.: funcionários e seus gerentes, que estão na 
    mesma tabela).
- Analisar relações hierárquicas (ex.: estrutura organizacional).
- Filtrar dados com base em condições internas.
*/

SELECT
    f.empno    AS 'ID Funcionário',
    f.ename    AS 'Nome Funcionário',
    f.job      AS 'Cargo',
    g.empno    AS 'ID Gerente',
    g.ename    AS 'Nome Gerente',
    g.job      AS 'Cargo Gerente'
FROM
    emp f  -- Alias para funcionários (f = "funcionário")
JOIN
    emp g  -- Alias para gerentes (g = "gerente")
ON
    f.mgr = g.empno;  -- Relação: o campo 'mgr' do funcionário aponta para o 'empno' do gerente

/*
> Junções Não-Idênticas

junções não idênticas (também chamadas de junções tradicionais) são aquelas que relacionam 
tabelas diferentes com base em uma condição específica. Elas são o oposto das junções
idênticas (self-joins), que unem uma tabela a si mesma.
*/

SELECT
    e.ename,
    e.sal,
    s.grade,
    s.losal,
    s.hisal
FROM 
    emp e
JOIN 
    salgrade s 
ON
    e.sal BETWEEN s.losal and s.hisal; -- Verifica se e.sal está no intervalo [s.losal, s.hisal]

/*
> Junção Tridimentsional

Uma junção tridimensional (ou multi-tabela) ocorre quando três ou mais tabelas são
relacionadas em uma única consulta para extrair dados combinados de múltiplas fontes.
Essa técnica é essencial quando você precisa:

- Combinar informações complementares de várias tabelas (ex.: pedidos + 
    clientes + produtos).
- Criar relatórios complexos com dados inter-relacionados.
- Resolver consultas que envolvem múltiplas relações de chave estrangeira.
*/
SELECT
    e.ename,  -- emp table
    e.sal,
    e.deptno,
    s.losal,  -- salgrade table
    s.hisal,
    d.dname,  -- dept table
    d.loc
FROM
    emp e
JOIN 
    dept d ON e.deptno = d.deptno -- Condição de Junção
JOIN  
    salgrade s ON e.sal BETWEEN s.losal and s.hisal -- Condição de Junção
WHERE -- Condição de Ouput
    e.sal > 1800;

/*
> Junção à Esquerda

Uma LEFT JOIN (ou LEFT OUTER JOIN) retorna todos os registros da tabela à 
esquerda (primeira tabela mencionada), mesmo que não haja correspondência 
na tabela à direita. Quando não há correspondência, os resultados das colunas da tabela à direita serão NULL.

Sintax:

SELECT colunas
FROM tabela_esquerda
LEFT JOIN tabela_direita ON tabela_esquerda.chave = tabela_direita.chave
*/

SELECT 
    e.ename,
    d.deptno,
    d.dname
FROM 
    scott.dept d
LEFT JOIN
    scott.emp e 
ON
    e.deptno = d.deptno;
ORDER BY
    d.dname ABC;