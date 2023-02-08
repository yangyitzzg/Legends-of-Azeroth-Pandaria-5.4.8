-- add wow token trinity string
DELETE FROM `trinity_string` WHERE `entry` IN (30007,30008,30009,30010);
INSERT INTO `trinity_string`(`entry`, `content_default`, `content_loc1`, `content_loc2`, `content_loc3`, `content_loc4`, `content_loc5`, `content_loc6`, `content_loc7`, `content_loc8`, `content_loc9`, `content_loc10`, `content_loc11`, `content_female`, `content_female_loc1`, `content_female_loc2`, `content_female_loc3`, `content_female_loc4`, `content_female_loc5`, `content_female_loc6`, `content_female_loc7`, `content_female_loc8`, `content_female_loc9`, `content_female_loc10`, `content_female_loc11`) VALUES 
(30007, 'Thanks for helping the Pandaria 5.4.8 project, you just received donate coins: %f', NULL, NULL, NULL, '感谢帮助 Pandaria 5.4.8 项目,你刚获得了%f代币.', '感謝幫助 Pandaria 5.4.8 項目，你剛獲得了%f代幣.', NULL, NULL, 'Спасибо за помощь проекту Pandaria 5.4.8, вы только что получили очков пожертвования: %f', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(30008, 'You do not have the necessary token.', NULL, NULL, NULL, '你没有足够的代币.', '你沒有足夠的代幣.', NULL, NULL, 'У вас нет необходимого жетона.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(30009, 'You may not use this token whilst you are in combat or present in an arena or battleground.', NULL, NULL, NULL, '你无法在战斗中或者处于战场或竞技场中使用代币.', '你無法在戰鬥中或者處於戰場或競技場中使用代幣.', NULL, NULL, 'Вы не можете использовать этот жетон, пока находитесь в бою, на арене или поле боя.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(30010, 'Coins disabled.', NULL, NULL, NULL, '代币已禁用.', '代幣已禁用.', NULL, NULL, 'Жетоны отключены.', NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
