/*
 Navicat Premium Data Transfer

 Source Server         : Local
 Source Server Type    : MySQL
 Source Server Version : 50711
 Source Host           : localhost
 Source Database       : csci222

 Target Server Type    : MySQL
 Target Server Version : 50711
 File Encoding         : utf-8

 Date: 08/17/2016 16:51:40 PM
*/

SET NAMES utf8;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
--  Table structure for `bug`
-- ----------------------------
DROP TABLE IF EXISTS `bug`;
CREATE TABLE `bug` (
  `bug_id` int(11) NOT NULL,
  `creation_ts` varchar(255) DEFAULT NULL,
  `short_desc` varchar(255) DEFAULT NULL,
  `delta_ts` varchar(255) DEFAULT NULL,
  `reporter_accessible` int(11) DEFAULT NULL,
  `cclist_accessible` int(11) DEFAULT NULL,
  `classification_id` int(11) DEFAULT NULL,
  `classification` varchar(255) DEFAULT NULL,
  `product` varchar(255) DEFAULT NULL,
  `component` varchar(255) DEFAULT NULL,
  `version` varchar(255) DEFAULT NULL,
  `rep_platform` varchar(255) DEFAULT NULL,
  `op_sys` varchar(255) DEFAULT NULL,
  `bug_status` varchar(255) DEFAULT NULL,
  `resolution` varchar(255) DEFAULT NULL,
  `bug_file_loc` varchar(255) DEFAULT NULL,
  `status_whiteboard` varchar(255) DEFAULT NULL,
  `keywords` varchar(255) DEFAULT NULL,
  `priority` varchar(255) DEFAULT NULL,
  `bug_severity` varchar(255) DEFAULT NULL,
  `target_milestone` varchar(255) DEFAULT NULL,
  `everconfirmed` int(11) DEFAULT NULL,
  `reporter` varchar(255) NOT NULL,
  `assigned_to` varchar(255) DEFAULT NULL,
  `votes` int(11) DEFAULT '0',
  PRIMARY KEY (`bug_id`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

SET FOREIGN_KEY_CHECKS = 1;
