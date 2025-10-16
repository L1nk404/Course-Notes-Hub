drop database Livraria;
create database Livraria;
use Livraria;

create table Categoria (
	Numero int(3) primary key auto_increment not null,
	Tipo char (20) not null
	);
insert Categoria values (0, "Livros");
insert Categoria values (0, "Dvd");

create table Produtos (
	Id int(3) primary key auto_increment not null,
	Nome char(25) not null,
	Preco decimal (6,2) not null,
	CatNum int(3) not null,
	
	foreign key(CatNum) references Categoria(Numero)
	);
insert Produtos values (0, "Codigo da Vinci", 39.99, 1);
insert Produtos values (0, "Diario de um mago", 19.99, 1);
insert Produtos values (0, "Hancock", 89.99, 2);
insert Produtos values (0, "Eu sou a lenda", 79.99, 2);