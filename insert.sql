insert into Scientists (name, gender, dob, dod, country) values
('John D Carmack','M',1970,0,'American'),
('Alan Turing','M',1912,1954,'English'),
('Dennis MacAlistair Ritchie','M',1941,2011,'American'),
('Linus Benedict Torvalds','M',1969,0,'Finnish'),
('Bjarne Stroustrup','M',1950,0,'Danish'),
('Ada Lovelace','F',1815,1852,'English'),
('Marissa Ann Mayer','F',1975,0,'American'),
('Steve Wozniak','M',1950,0,'American'),
('Grace Hopper','F',1906,1992,'American'),
('James Gosling','M',1955,0,'American');

insert into Computers (name, buildy, type, built) values
('Commodor Amiga',1987,'PC',TRUE),
('Babbage Difference Engine',1991,'Calculating',TRUE),
('Colossus',1944,'Calculating',TRUE),
('Eniac',1946,'Universal',TRUE),
('Manchester Baby',1948,'Universal',TRUE),
('Playstation',1994,'Console',TRUE),
('Deep Blue',1989,'Chess',TRUE),
('Turing Machine',1936,'Computation',TRUE),
('Hal 9000',1992,'Sentient',FALSE),
('Deep Thought',0,'Ultimate Answer',FALSE);

insert into Scientist_has_Computer values
(1, 1),
(3, 3),
(2, 8);
