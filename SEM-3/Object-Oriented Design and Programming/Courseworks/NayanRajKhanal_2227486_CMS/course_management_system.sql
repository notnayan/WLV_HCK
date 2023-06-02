-- phpMyAdmin SQL Dump
-- version 5.2.0
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Feb 09, 2023 at 12:15 PM
-- Server version: 10.4.24-MariaDB
-- PHP Version: 8.0.19

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `course_management_system`
--

-- --------------------------------------------------------

--
-- Table structure for table `auth`
--

CREATE TABLE `auth` (
  `id` int(11) NOT NULL,
  `name` varchar(100) DEFAULT NULL,
  `email` varchar(100) DEFAULT NULL,
  `password` varchar(100) DEFAULT NULL,
  `role` varchar(25) DEFAULT NULL,
  `phoneNo` varchar(25) DEFAULT NULL,
  `course` varchar(20) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `auth`
--

INSERT INTO `auth` (`id`, `name`, `email`, `password`, `role`, `phoneNo`, `course`) VALUES
(1, 'Nayan', 'nayan@gmail.com', 'Nayan@123', 'Student', '9804302504', 'BIT'),
(2, 'Habibi', 'habibi@gmail.com', 'Habibi@123', 'Student', '9804302501', 'BIBM'),
(3, 'Bruh', 'bruh@gmail.com', 'Bruh@123', 'Student', '9804302501', 'IMBA'),
(4, 'Balen', 'balen@gmail.com', 'Balen@123', 'Teacher', '9804302509', 'BIT'),
(5, 'Severus', 'severus@gmail.com', 'Severus@123', 'Teacher', '9804302500', 'IMBA'),
(6, 'Thanos', 'thanos@gmail.com', 'thanos@123', 'Teacher', '9804302508', 'BIBM'),
(7, 'Admin', 'admin@gmail.com', 'Admin@123', 'Admin', '9804302507', NULL);

-- --------------------------------------------------------

--
-- Table structure for table `courses`
--

CREATE TABLE `courses` (
  `course_id` int(11) NOT NULL,
  `course_name` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `courses`
--

INSERT INTO `courses` (`course_id`, `course_name`) VALUES
(1, 'BIT'),
(2, 'BIBM'),
(3, 'IMBA');

-- --------------------------------------------------------

--
-- Table structure for table `modules`
--

CREATE TABLE `modules` (
  `module_id` int(11) NOT NULL,
  `module_name` varchar(100) NOT NULL,
  `module_type` varchar(100) NOT NULL,
  `course_id` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `modules`
--

INSERT INTO `modules` (`module_id`, `module_name`, `module_type`, `course_id`) VALUES
(1, 'Computational Mathematics', 'core', 1),
(2, 'Fundamentals of Computing', 'core', 1),
(3, 'Internet Software Architecture', 'core', 1),
(4, 'Academic Skills and Team-Based Learning', 'optional', 1),
(5, 'Embedded System Programming', 'core', 1),
(6, 'Introductory Programming and Problem Solving', 'core', 1),
(7, 'Database', 'optional', 1),
(8, 'OOP', 'core', 1),
(9, '21st Century Management', 'core', 2),
(10, 'Preparing for Success at University', 'optional', 2),
(11, 'Principles of Business', 'core', 2),
(12, 'Project Based Learning', 'core', 2),
(13, 'The Digital Business', 'core', 2),
(14, 'The Innovative Business', 'optional', 2),
(15, 'The Responsible Business', 'optional', 2),
(16, 'The Sustainable Business', 'core', 2),
(17, 'Strategic Global Marketing', 'core', 3),
(18, 'Financial Decision Making', 'core', 3),
(19, 'The Masters Research Project I', 'optional', 3),
(20, 'The Masters Professional Project II', 'optional', 3),
(21, 'Contemporary Issues in Human Resources An International Perspective', 'core', 3),
(22, 'Strategic Operations Management', 'core', 3),
(23, 'The Masters Professional Project II', 'optional', 3),
(24, 'The Masters Professional Project II', 'optional', 3);

-- --------------------------------------------------------

--
-- Table structure for table `results`
--

CREATE TABLE `results` (
  `student_id` int(11) NOT NULL,
  `module_id` int(11) NOT NULL,
  `marks` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `results`
--

INSERT INTO `results` (`student_id`, `module_id`, `marks`) VALUES
(1, 1, 99),
(1, 2, 1),
(1, 3, 40),
(1, 4, 75),
(1, 5, 88),
(1, 6, 39),
(1, 7, 41),
(1, 8, 100);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `auth`
--
ALTER TABLE `auth`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `courses`
--
ALTER TABLE `courses`
  ADD PRIMARY KEY (`course_id`);

--
-- Indexes for table `modules`
--
ALTER TABLE `modules`
  ADD PRIMARY KEY (`module_id`),
  ADD KEY `course_id` (`course_id`);

--
-- Indexes for table `results`
--
ALTER TABLE `results`
  ADD PRIMARY KEY (`student_id`,`module_id`),
  ADD KEY `module_id` (`module_id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `auth`
--
ALTER TABLE `auth`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT for table `courses`
--
ALTER TABLE `courses`
  MODIFY `course_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT for table `modules`
--
ALTER TABLE `modules`
  MODIFY `module_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=25;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `modules`
--
ALTER TABLE `modules`
  ADD CONSTRAINT `modules_ibfk_1` FOREIGN KEY (`course_id`) REFERENCES `courses` (`course_id`);

--
-- Constraints for table `results`
--
ALTER TABLE `results`
  ADD CONSTRAINT `results_ibfk_1` FOREIGN KEY (`student_id`) REFERENCES `auth` (`id`),
  ADD CONSTRAINT `results_ibfk_2` FOREIGN KEY (`module_id`) REFERENCES `modules` (`module_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
