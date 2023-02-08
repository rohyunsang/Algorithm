-- 코드를 입력하세요
SELECT FACTORY_ID, FACTORY_NAME, ADDRESS FROM FOOD_FACTORY
-- FOOD_FACTORY table 에서 FACTORY_ID, FACTORY_NAME, ADDRESS를 가져옴
WHERE ADDRESS LIKE "강원도%"
-- ADDRESS 에서 "강원도"로 시작하는 주소 가져옴 
ORDER BY FACTORY_ID;
-- FACTORY_ID 오름차순으로 정렬 
