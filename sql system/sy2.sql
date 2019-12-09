#创建ITPro数据库
create database ITPro;

#使用ITPor数据库
use ITPro;

#创建PC表
create table PC (
    model int not null primary key,
    speed decimal(3,2),
    ram int,
    hd int,
    price int
);

#PC表中插入数据
insert into PC values('1001','2.66','1024','250','2114');
insert into PC values('1002','2.10','512','250','995');
insert into PC values('1003','1.42','512','80','478');
insert into PC values('1004','2.80','1024','250','649');
insert into PC values('1005','3.20','512','250','630');
insert into PC values('1006','3.20','1024','320','1049');
insert into PC values('1007','2.20','1024','200','510');
insert into PC values('1008','2.20','2048','250','770');
insert into PC values('1009','2.00','1024','250','650');
insert into PC values('1010','2.80','2048','300','770');
insert into PC values('1011','1.86','2048','160','959');
insert into PC values('1012','2.80','1024','160','649');
insert into PC values('1013','3.06','512','80','529');

#创建Laptop表
create table Laptop (
    model int not null primary key,
    speed decimal(3,2),
    ram int,
    hd int,
    screen decimal(3,1),
    price int
);

#Laptop表中插入数据
insert into Laptop values(2001,'2.00',2048,240,'20.1',3673);
insert into Laptop values(2002,'1.73',1024,80,'17.0',949);
insert into Laptop values(2003,'1.80',512,60,'15.4',549);
insert into Laptop values(2004,'2.00',512,60,'13.3',1150);
insert into Laptop values(2005,'2.16',1024,120,'17.0',2500);
insert into Laptop values(2006,'2.00',2048,80,'15.4',1700);
insert into Laptop values(2007,'1.83',1024,120,'13.3',1429);
insert into Laptop values(2008,'1.60',1024,100,'15.4',900);
insert into Laptop values(2009,'1.60',512,80,'14.1',680);
insert into Laptop values(2010,'2.00',2048,160,'15.4',2300);

#创建Printer表
create table Printer (
    model int not null primary key,
    color char(10),
    type char(10),
    price int
);

#Printer表中插入数据
insert into Printer values(3001,'true','ink-jet',99);
insert into Printer values(3002,'false','laser',239);
insert into Printer values(3003,'true','laser',899);
insert into Printer values(3005,'false','laser',120);
insert into Printer values(3006,'true','ink-jet',100);
insert into Printer values(3007,'true','laser',200);

#创建product表
create table product (
    maker char(5),
    model int not null primary key,
    type char(10)
);

#product表中插入数据
insert into product values('A','1001','pc');
insert into product values('A','1002','pc');
insert into product values('A','1003','pc');
insert into product values('A','2004','laptop');
insert into product values('A','2005','laptop');
insert into product values('A','2006','laptop');
insert into product values('B','1004','pc');
insert into product values('B','1005','pc');
insert into product values('B','1006','pc');
insert into product values('B','2007','laptop');
insert into product values('C','1007','pc');
insert into product values('D','1008','pc');
insert into product values('D','1009','pc');
insert into product values('D','1010','pc');
insert into product values('D','3004','printer');
insert into product values('D','3005','printer');
insert into product values('E','1011','pc');
insert into product values('E','1012','pc');
insert into product values('E','1013','pc');
insert into product values('E','2001','laptop');
insert into product values('E','2002','laptop');
insert into product values('E','2003','laptop');
insert into product values('E','3001','printer');
insert into product values('E','3002','printer');
insert into product values('F','2008','laptop');
insert into product values('F','2009','laptop');
insert into product values('G','2010','laptop');
insert into product values('H','3006','printer');
insert into product values('H','3007','printer');

#创建Ship数据库
create database Ship;

#使用Ship数据库
use Ship;

#创建Classes表
create table Classes(
    class char(20) not null primary key,
    type char(5),
    country char(10),
    numGuns int,
    bore int,
    displacement int
);

#Classes表中添加数据
insert into Classes values('Bismarck','bb','Germany',8,15,42000);
insert into Classes values('Iowa','bb','USA',9,16,46000);
insert into Classes values('Kongo','bc','Japan',8,14,32000);
insert into Classes values('North Carolina','bb','USA',9,16,37000);
insert into Classes values('Renown','bc','Gt.Britain',6,15,32000);
insert into Classes values('Revenge','bb','Gt.Britain',8,15,29000);
insert into Classes values('Tennessee','bb','USA',12,14,32000);
insert into Classes values('Yamato','bb','Japan',9,18,65000);

#创建Battle表
create table Battle (
    name char(20) not null primary key,
    date char(20)
);

#Battle表中添加数据
insert into Battle values('Demmark Strait','5/24-27/41');
insert into Battle values('Guadalcanal','11/15/42');
insert into Battle values('Suriago Strait','10/25/44');

#创建Outcomes表
create table Outcomes(
    ship char(20) not null primary key,
    battle char(20),
    result char(7)
);

#Outcomes表中添加数据
insert into Outcomes values('Arizona','Pearl Harbor','sunk');
insert into Outcomes values('Bismarck','Denmark Strait','sunk');
insert into Outcomes values('California','Surigao Strait','ok');
insert into Outcomes values('Duke of York','North Cape','ok');
insert into Outcomes values('Fuso','Surigao Strait','sunk');
insert into Outcomes values('Hood','Denmark Strait','sunk');
insert into Outcomes values('King George V','Denmark Strait','ok');
insert into Outcomes values('Kirishima','Guadalcanal','sunk');
insert into Outcomes values('Prince of Wales','Denmark Strait','damaged');
insert into Outcomes values('Rodney','Denmark Strait','ok');
insert into Outcomes values('Scharnhorst','North Cape','sunk');
insert into Outcomes values('South Dakota','Guadalcanal','damaged');
insert into Outcomes values('Tennessee','Surigao Strait','ok');
insert into Outcomes values('Washington','Guadalcanal','ok');
insert into Outcomes values('West Virginia','Surigao Strait','ok');
insert into Outcomes values('Yamashiro','Surigao Strait','sunk');

#创建Ships表
create table Ships (
    name char(20) not null primary key,
    class  char(20),
    launched int
);

#Ships表中添加数据
insert into Ships values('California','Tennessee',1921);
insert into Ships values('Haruna','Kongo',1915);
insert into Ships values('Hiei','Kongo',1914);
insert into Ships values('Iowa','Iowa',1943);
insert into Ships values('Kirishima','Kongo',1915);
insert into Ships values('Kongo','Kongo',1913);
insert into Ships values('Missouri','Iowa',1944);
insert into Ships values('Musashi','Yamato',1942);
insert into Ships values('New Jersey','Iowa',1943);
insert into Ships values('North Carolina','North Carolina',1941);
insert into Ships values('Ramillies','Revenge',1917);
insert into Ships values('Renown','Renown',1916);
insert into Ships values('Repulse','Renown',1916);
insert into Ships values('Resolution','Revenge',1916);
insert into Ships values('Revenge','Revenge',1916);
insert into Ships values('Royal Oak','Revenge',1916);
insert into Ships values('Royal Sovereign','Revenge',1916);
insert into Ships values('Tennessee','Tennessee',1920);
insert into Ships values('Washington','North Carolina',1941);
insert into Ships values('Wisconsin','Iowa',1944);
insert into Ships values('Yamato','Yamato',1941);

#创建Movie数据库
create database Movie;

#使用Movie数据库
use Movie;

#创建Movies表
create table Movies (
    title varchar(30) not null,
    year int not null,
    length int,
    genre varchar(20),
    studioName varchar(30),
    `produecerC#` int,
    constraint tl primary key (title,year)
);

#Movies表添加数据
insert into Movies values('The Shawshank Redemption',1994,142,'sin','Columbia Pivtures','35252');
insert into Movies values('Star Wars',1977,124,'sciFi','Fox',12345);
insert into Movies values('Pacific Rim',1991,104,'commedy','Disney',67890);

#创建MovieStar表
create table MovieStar(
    name varchar(20) not null primary key,
    address varchar(30) not null,
    gender varchar(2),
    brirhdate date
);

#MovieStar表中添加数据
insert into MovieStar values('Tim Robbins','USA','男','1958-10-16');
insert into MovieStar values('Felicity Jones','UK','男','1983-10-17');
insert into MovieStar values('Charlie Hunnam','UK','女','1980-4-10');

#创建StarsIn表
create table StarsIn (
    movieTitle varchar(30) not null,
    movieYear int not null,
    starName varchar(20) not null,
    constraint mms primary key (movieTitle,movieYear,starName)

);

#StarsIn中添加数据
insert into StarsIn values('The Shawshank Redemption',1994,'Tim Robbins');
insert into StarsIn values('Star Wars',1977,'Felicity Jones');
insert into StarsIn values('Pacific Rim',1991,'Charlie Hunnam');

#创建MovieExec表
create table MovieExec (
    name varchar(20),
    address varchar(60),
    `cert#` int not null primary key,
    netWorth int
);

#MovieExec表中添加数据
insert into MovieExec values('Tim Robbins','USA',123,345);
insert into MovieExec values('Felicity Jones','UK',978,757);
insert into MovieExec values('Charlie Hunnam','UK',231,989);

#创建Studio表
create table Studio
    (name varchar(30) not null primary key,
    address varchar(60),
    `presC#` int
);

#Studio表中添加数据
insert into Studio values('Disney','USA',12345);
insert into Studio values('Warner Bros','USA',12123);
insert into Studio values('Twentieth Century-Fox','USA',23614);

#MovieStar表中添加phone字段
alter table MovieStar add phone varchar(11);

#MovieSta表建立check约束
alter table MovieStar add constraint S1 check(gender='男'or gender='女');

#创建外键约束
alter table StarsIn add constraint s1_fk foreign key (movieTitle,movieYear) references Movies(title,year);
alter table StarsIn add constraint s3_fk foreign key (starName) references MovieStar(name);