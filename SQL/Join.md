## Relacionamento: 

**Categoria:**
- Numero: Int, Auto Increment, Primary
- Tipo: Varchar(50), Not Null
  
```
+--------+----------+------+-----+---------+----------------+

| Field | Type | Null | Key | Default | Extra |

+--------+----------+------+-----+---------+----------------+

| Numero | int(3) | NO | PRI | NULL | auto_increment |

| Tipo | char(20) | NO | | NULL | |

+--------+----------+------+-----+---------+----------------+
```
  
  

Produto:

- Id: Int, Primary, Auto Increment

- Nome: Varchar(50), Not Null

- Preco: decimal(6,2), Not Null

- CatNum_FK: Int, Not Null, foreign key(CatNum) references Categoria(Numero)

  

+--------+--------------+------+-----+---------+----------------+

| Field | Type | Null | Key | Default | Extra |

+--------+--------------+------+-----+---------+----------------+

| Id | int(3) | NO | PRI | NULL | auto_increment |

| Nome | char(25) | NO | | NULL | |

| Preco | decimal(6,2) | NO | | NULL | |

| CatNum | int(3) | NO | MUL | NULL | |

+--------+--------------+------+-----+---------+----------------+

  
  

===========================================================

  

[Categoria] (0,n)-- <Possui> --(0,n) [Produtos]

  
  

INNER JOIN: ===============================

Esta instrução SQL serve para unir os resultados do relacionamento de duas

ou mais tabelas. Conhecida como uma conexão interna.

  

SELECT Tabela1.Coluna1

FROM Tabela1 INNER JOIN TABELA2

ON Tabela1.ChaveEstrangeira = Tabela2.ChavePrimária;

  

[!] We can also check the key referenced by using:

SHOW CREATE TABLE <table>;