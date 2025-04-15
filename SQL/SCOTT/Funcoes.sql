/*
Funções são usadas para manipular itens e dados

- Funções são usadas para manipular itens de dados.
    - Elas aceitam um ou mais argumentos e retornam um valor 
    para cada linha retornada pela consulta
- AS funções são utilizadas para manipular caracteres,
    números, datas e para conversão de dados.


Funções podem ser usadas tanto para manipular apenas o output, 
como para manipular os dados, por exemplo:

-- 1. UPPER apenas para visualização (não altera):
SELECT ename, UPPER(ename) AS "Nome Maiúsculo" FROM emp;

-- 2. UPPER modificando dados (altera):
UPDATE emp SET ename = UPPER(ename) WHERE deptno = 10;
*/

SHOW DATABASES;

USE scott;

-- EXEMPLOS:

/*
LOWER(arg1)/UPPER(arg1) - Converte uma cadeia de caracteres em 
letras minúsculas/maiúsculas.
*/
SELECT LOWER(ename) FROM emp;

/*
INITCAP(arg1) - Converte a primeira letra de cada palavra em
maiúscula e mantém o resto em minúsculo. 
! Doesn't exist in MYSQL !
*/

/*
CONCAT(arg1, arg2, ...) - Concacatena valores.
*/

-- Função CONCAT
SELECT CONCAT(ename, ' trabalha como ', job) FROM emp;

