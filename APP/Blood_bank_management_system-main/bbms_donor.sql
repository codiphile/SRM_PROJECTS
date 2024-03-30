-- MySQL dump 10.13  Distrib 8.0.34, for macos13 (arm64)
--
-- Host: localhost    Database: bbms
-- ------------------------------------------------------
-- Server version	8.1.0

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `donor`
--

DROP TABLE IF EXISTS `donor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `donor` (
  `donorId` int NOT NULL,
  `name` varchar(100) DEFAULT NULL,
  `fatherName` varchar(100) DEFAULT NULL,
  `motherName` varchar(100) DEFAULT NULL,
  `DOB` varchar(20) DEFAULT NULL,
  `MobileNo` varchar(10) DEFAULT NULL,
  `gender` varchar(10) DEFAULT NULL,
  `email` varchar(100) DEFAULT NULL,
  `bloodGroup` varchar(10) DEFAULT NULL,
  `city` varchar(100) DEFAULT NULL,
  `address` varchar(500) DEFAULT NULL,
  PRIMARY KEY (`donorId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `donor`
--

LOCK TABLES `donor` WRITE;
/*!40000 ALTER TABLE `donor` DISABLE KEYS */;
INSERT INTO `donor` VALUES (1,'Gaurav Kumar Singh','Sunil Kumar','Nisha Kumari','06-08-1990','8882281628','Male','gauravx@gmail.com','AB+','Patna','Patna,Bihar,India'),(2,'Amit Kumar','Anil Kumar','Prity Kumari','09-08-1990','7676745675','Male','amit@gmail.com','A+','jaipur','jaipur,rajasthan,India'),(3,'RAKESH','MUKESH','LALITA','11-08-1995','9898959534','Male','raks@gmail.com','A+','vadodara','vadodara,gujrat'),(4,'Aveeck Pandey','Ajay Pandey','Veronica Pandey','25-02-2003','8278694805','Male','aveeckKumarpandey@gmail.com','AB+','Chennai','205,Nelson Mandela, Chennai, India'),(5,'manas jhota','pawan jotwani','jhanvi jotwani','10-10-2004','8090262331','Male','mj4134@srmist.edu.in','O+','chennai','estancia, chennai'),(6,'Abhinav Singh','Shailesh Kumar','Kumari Sunita','30-08-2004','8789803442','Male','abhinavsingh123@gmail.com','O+','patna','boring road, patna, 800010'),(7,'Yashal khan','sajid khan','zubaida','20-01-2003','7070964565','Female','yashal@gmail.com','B+','chennai','esq, srmist,chennai'),(8,'Srishti singh','Jayant Singh','Minakshi Singh','04-10-2004','7309014000','Female','srishtisingh200@gmail.com','O+','Chennai','srm esq a block');
/*!40000 ALTER TABLE `donor` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-12-12 11:00:41
