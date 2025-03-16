-- DDL (Data definition Language)

-- Creating Table

USE BibliotecaNacional; -- Accessing BibliotecaNacional Data Base

-- Creating Tables

CREATE TABLE Categoria (
    cod_cat INT(4) PRIMARY KEY,
    descricao VARCHAR(500)
);

CREATE TABLE Livros (
    isbn INT(4) PRIMARY KEY,
    titulo VARCHAR(5) NOT NULL, -- cannot be NUL
    ano INT(4),
    editora VARCHAR(50),
    cod_cat INT(4) REFERENCES Categoria (cod_Cat)
);
    
CREATE TABLE Autor (
    cod_autor INT(4) PRIMARY KEY,
    nome varchar(50),
    nacionalidade VARCHAR(50),
    sexo ENUM('M', 'F', 'O') -- analog to genero CHAR(1) CHECK (genero IN ('M', 'F'))
);

CREATE TABLE Lancamento (
    isbn INT(4) REFERENCES Livros (isbn),
    cod_autor INT(4) REFERENCES Autor (cod_autor),
    data_lanc DATE
)

-- editing tables

-- Add a column	        ADD COLUMN column_name column_type;
-- Modify a column	    MODIFY COLUMN column_name new_data_type;
-- Rename a column	    CHANGE COLUMN old_name new_name type;
-- Remove a column	    DROP COLUMN column_name;
-- Rename table	        RENAME TO new_table_name;
-- Add constraint	    ADD CONSTRAINT constraint_name CHECK (...);
-- Remove constraint	DROP CHECK constraint_name;
-- Add index	        ADD INDEX index_name (column);
-- Remove index	        DROP INDEX index_name;

-- Examples:

-- Adding a new collum called test
ALTER TABLE Autor
ADD COLUMN test VARCHAR(50); 

DESCRIBE Autor;

-- Modifying an existing collumn
ALTER TABLE Autor
MODIFY COLUMN test INT(4); -- Changing type

DESCRIBE Autor;

ALTER TABLE Autor
CHANGE COLUMN test new_test INT(4); -- Renaming

DESCRIBE Autor;

ALTER TABLE Autor
DROP COLUMN new_test; -- Removing column

DESCRIBE Autor;