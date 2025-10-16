-- Relacionamento: =====================

-- Categoria:
-- - Numero: Int, Auto Increment, Primary
-- - Tipo: Varchar(50), Not Null

-- +--------+----------+------+-----+---------+----------------+
-- | Field  | Type     | Null | Key | Default | Extra          |
-- +--------+----------+------+-----+---------+----------------+
-- | Numero | int(3)   | NO   | PRI | NULL    | auto_increment |
-- | Tipo   | char(20) | NO   |     | NULL    |                |
-- +--------+----------+------+-----+---------+----------------+


-- Produto:
-- - Id: Int, Primary, Auto Increment
-- - Nome: Varchar(50), Not Null
-- - Preco: decimal(6,2), Not Null
-- - CatNum_FK: Int, Not Null, foreign key(CatNum) references Categoria(Numero)

-- +--------+--------------+------+-----+---------+----------------+
-- | Field  | Type         | Null | Key | Default | Extra          |
-- +--------+--------------+------+-----+---------+----------------+
-- | Id     | int(3)       | NO   | PRI | NULL    | auto_increment |
-- | Nome   | char(25)     | NO   |     | NULL    |                |
-- | Preco  | decimal(6,2) | NO   |     | NULL    |                |
-- | CatNum | int(3)       | NO   | MUL | NULL    |                |
-- +--------+--------------+------+-----+---------+----------------+


-- ===========================================================

-- [Categoria] (0,n)-- <Possui> --(0,n) [Produtos]


-- INNER JOIN: ===============================
-- Esta instrução SQL serve para unir os resultados do relacionamento de duas
-- ou mais tabelas. Conhecida como uma conexão interna.

-- SELECT Tabela1.Coluna1
-- FROM Tabela1 INNER JOIN TABELA2
-- ON Tabela1.ChaveEstrangeira = Tabela2.ChavePrimária;

-- [!] We can also check the key referenced by using:
--   SHOW CREATE TABLE <table>;


SELECT Categoria.Tipo, Produto.Nome, Produto.Preco
    FROM Produto INNER JOIN Categoria
    ON Produto.CatNum = Categoria.Numero;

-- Exercício 
-- 1) Insira duas novas categorias, chamadas "escritório", "doces"
INSERT INTO Categoria (Numero,Tipo)
VALUES
(0, 'Escritório'),
(0, 'Doces');

-- 3) Faça uma consulta que retorne as seguintes colunas na ordem
--      ID do Produto, Nome, Preço, Tipo, Categoria
SELECT 
    p.ID,
    p.Nome,
    p.Preco, 
    c.Tipo
FROM 
    Produto p 
JOIN
    Categoria c
ON
    p.CatNum = c.Numero;

-- LEFT JOIN: ====================================================
-- A instrução SQL LEFT JOIN retorna a tabela1 inteira e apenas os registros
-- que coincidem com a igualdade do join da Tabela2.

-- SELECT Tabela1.*, Tabela2.*
-- FROM Tabela1 LEFT JOIN TABELA2
-- ON Tabela1.ChaveEstrangeira = Tabela2.ChavePrimária;