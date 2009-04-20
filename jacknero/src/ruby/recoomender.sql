DROP TABLE IF EXISTS `vaxis`;
CREATE TABLE `vaxis` (
	`id` int(11) NOT NULL auto_increment,
	`name` varchar(255) character set utf8 collate utf8_bin NOT NULL,
	`title` text,
	`description` text,
	PRIMARY KEY (`id`),
	UNIQUE KEY `name` (`name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;


DROP TABLE IF EXISTS `haxis`;
CREATE TABLE `haxis` (
	`id` int(11) NOT NULL auto_increment,
	`name` varchar(255) character set utf8 collate utf8_bin NOT NULL,
	`title` text,
	`description` text,
	PRIMARY KEY (`id`),
	UNIQUE KEY `name` (`name`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `vaxis_cc`;
CREATE TABLE `vaxis_cc` (
	`id` int(11) NOT NULL auto_increment,
	`x_id` int(11) NOT NULL,
	`y_id` int(11) NOT NULL,
	`value` float NOT NULL,
	PRIMARY KEY (`id`),
	UNIQUE KEY `x_id` (`x_id`,`y_id`),
	KEY `x_id_index` (`x_id`),
	KEY `y_id_index` (`y_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;



DROP TABLE IF EXISTS `haxis_cc`;
CREATE TABLE `haxis_cc` (
	`id` int(11) NOT NULL auto_increment,
	`x_id` int(11) NOT NULL,
	`y_id` int(11) NOT NULL,
	`value` float NOT NULL,
	PRIMARY KEY (`id`),
	UNIQUE KEY `x_id` (`x_id`,`y_id`),
	KEY `x_id_index` (`x_id`),
	KEY `y_id_index` (`y_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;


DROP TABLE IF EXISTS `vector`;
CREATE TABLE `vector` (
	`id` int(11) NOT NULL auto_increment,
	`vaxis_id` int(11) NOT NULL,
	`haxis_id` int(11) NOT NULL,
	`value` float NOT NULL,
	PRIMARY KEY (`id`),
	UNIQUE KEY `vaxis_id` (`vaxis_id`, `haxis_id`),
	KEY `vaxis_id_index` (`vaxis_id`),
	KEY `haxis_id_index` (`haxis_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;



