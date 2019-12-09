 #6.3.8
select pr.model,pr.maker ,p.speed, p.ram, p.hd, 0.0 as rd, p.price, 0.0 as screen, 0.0 as color, 0.0 as type
from Product pr, PC p
where p.model = pr.model
union
select pr.model,pr.maker ,l.speed, l.ram, l.hd, 0.0 as rd, l.price, l.screen, 0.0 as color, 0.0 as type
from Product pr, Laptop l
where l.model = pr.model
union
select pr.model,pr.maker ,0.0 as speed, 0.0 as ram, 0.0 as hd, 0.0 as rd, p.price, 0.0 as screen, p.color, p.type
from Product pr, Printer p
where p.model = pr.model

#6.1.2
select `address`
from Studio
where name = "MGM"

select birthdate
from MovieStar
where name ="Sandra Bullock"

select starName
from StarsIn
where movieYear = 1980 or movieTitle like "%LOVE%"

select name
from MovieExec
where netWorth >= 10000000

select name
from MovieStar
where gender = "男" or address like "%Malibu%"

#6.1.3
select model, speed, hd
from PC
where price < 1000

select model, speed as gigahertz, hd as gigabytes
from PC
where price < 1000

select distinct maker
from Product
where model in (
	select model
	from Printer
)

select model, ram, screen
from Laptop
where price > 1500

select * 
from Printer
where color = "true"

select model, hd
from PC
where speed = 3.2 and price < 2000

#6.1.4
select class, country
from CLasses
where numGuns >= 10

select name as ShipName
from Ships
where launched < 1918

select ship, battle
from Outcomes
where result = "sunk"

select name
from Ships
where name = class

select name 
from Ships
where name like "R%"

select name 
from Ships
where name like "_% _% _%"

#6.2.1
select MovieStar.name
from MovieStar, StarsIn
where MovieStar.name = StarsIn.name 
		and MovieStar.gender = "男" 
		and StarsIn.movieTitle = "Titanic"

select s.starName
from Movies m, StarsIn s, Studio t
where t.name = "MGM"
		and m.year = 1995
		and m.title = s.movieTitle
		and m.studioName = t.name 

select e.name
from MovieExec e, Studio t
where e.`cert#` and t.`presC#`
		and t.name = 'MGM'
		
select m1.title
from Movies m1, Movies m2
where m1.length > m2.length
		and m2.title = "Gone with the wind"
		
select e1.name
from MovieExec e1, MovieExec e2
where e1.netWorth > e2.netWorth
		and e2.name = "Merv Griffin"

#6.2.2
select pr.maker, l.speed
from Product pr, Laptop l
where pr.model = l.model and l.hd >= 30

select PC.model, PC.price
from PC, Product
where Product.maker = "B" and PC.model = Product.model
union
select Laptop.model, Laptop.price
from Laptop, Product
where Product.maker = "B" and Laptop.model = Product.model
union
select Printer.model, Printer.price
from Printer, Product
where Product.maker = "B" and Printer.model = Product.model

select distinct pr.maker
from Product pr, Laptop l
where pr.model = l.model and pr.maker not in (
	select pr.maker
	from Product pr, PC p
	where pr.model = p.model
)

select distinct p.hd
from PC p, PC p1
where p.hd = p1.hd and p.model > p1.model


