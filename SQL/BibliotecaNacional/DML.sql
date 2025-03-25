-- DML (Data Manipulation Language)

-- Disable foreign key checks to allow inserting data in any order
SET FOREIGN_KEY_CHECKS = 0;

-- Insert data into Categoria table
INSERT INTO Categoria (cod_cat, descricao)
VALUES
(1, 'Fiction'),
(2, 'Non-Fiction'),
(3, 'Science'),
(4, 'History'),
(5, 'Biography');

-- Insert data into Autor table
INSERT INTO Autor (cod_autor, nome, nacionalidade, sexo)
VALUES
(1, 'George Orwell', 'British', 'M'),
(2, 'J.K. Rowling', 'British', 'F'),
(3, 'Yuval Noah Harari', 'Israeli', 'M'),
(4, 'Jane Austen', 'British', 'F'),
(5, 'Stephen Hawking', 'British', 'M');

-- Insert data into Livros table
INSERT INTO Livros (isbn, titulo, ano, editora, cod_cat)
VALUES
(101, '1984', 1949, 'Secker & Warburg', 1), -- Fiction
(102, "Harry Potter and the Philosopher's Stone", 1997, 'Bloomsbury', 1), -- Fiction
(103, 'Sapiens: A Brief History of Humankind', 2011, 'Harper', 2), -- Non-Fiction
(104, 'Pride and Prejudice', 1813, 'T. Egerton, Whitehall', 1), -- Fiction
(105, 'A Brief History of Time', 1988, 'Bantam Books', 3); -- Science

-- Insert data into Lancamento table
INSERT INTO Lancamento (isbn, cod_autor, data_lanc)
VALUES
(101, 1, '1949-06-08'), -- 1984 by George Orwell
(102, 2, '1997-06-26'), -- Harry Potter by J.K. Rowling
(103, 3, '2011-02-10'), -- Sapiens by Yuval Noah Harari
(104, 4, '1813-01-28'), -- Pride and Prejudice by Jane Austen
(105, 5, '1988-03-01'); -- A Brief History of Time by Stephen Hawking

-- Re-enable foreign key checks
SET FOREIGN_KEY_CHECKS = 1;
