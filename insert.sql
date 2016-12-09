insert into Scientists (name, gender, dob, dod, country) values
("John D Carmack",'M',1970,0,"American"),
("Alan Turing",'M',1912,1954,"English"),
("Dennis MacAlistair Ritchie",'M',1941,2011,"American"),
("Linus Benedict Torvalds",'M',1969,0,"Finnish"),
("Bjarne Stroustrup",'M',1950,0,"Danish"),
("Ada Lovelace",'F',1815,1852,"English"),
("Marissa Ann Mayer",'F',1975,0,"American"),
("Steve Wozniak",'M',1950,0,"American"),
("Grace Hopper",'F',1906,1992,"American"),
("James Gosling",'M',1955,0,"American");

insert into Computers (name, buildy, type, built) values
("Commodor Amiga",1987,"PC",1),
("Babbage Difference Engine",1991,"Calculating",1),
("Colossus",1944,"Calculating",1),
("Eniac",1946,"Universal",1),
("Manchester Baby",1948,"Universal",1),
("Playstation",1994,"Console",1),
("Deep Blue",1989,"Chess",1),
("Turing Machine",1936,"Computation",1),
("Hal 9000",1992,"Sentient",0),
("Deep Thought",0,"Ultimate Answer",0);

insert into Scientist_has_Computer values
(1, 1),
(3, 3),
(2, 8);
