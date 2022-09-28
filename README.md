# Lab1Hammurabi


### Конспект тз
<details>
<summary>
Конспект тз
</summary>

- раунд
- игрок
- ресурсы
  - население
    - прирост(на каждый раунд)
  - акры земли
    - стоимость(на каждый раунд)
    - инком пшеницы(на каждый раунд)
  - бушели пшеницы
    - как еда
    - как посев
    - как валюту
- советник
- город
- крысы (едят пшеницу каждый раунд)
- чума - вероятность сократить насленеие
- условия победы N раундов
- условия поражения 
  - 0 население
  - % смертей от голода

</details>


### Действия
- Покупать акры (Пшеница валюта)
- Продавать акры (Пшеница валюта)
- Пшеница на семена - посев
- Пшеница на еду



### Последовательность в раунде
1. Инком пшеницы
2. Крысы
3. Трата на еду + смерть от голода
4. Проверка на голод - условие поражение
5. Инком жителей
6. Чума


### Сущности
- City
  - CitizenAmount
  - WheatAmount
  - AcreAmount

- Config
  - int CitizenWheatConsumption
  - int CitizenAcreHandleCount
  - int CitizenSeedWheatCost
  
- Round
  - int Number
  - RoundActions
    - AcreWheatIncome
      - int AcreWheatIncome
    - Rats
      - int RatsAtePercentage
    - CitizenWheatConsumption
    - LoseCondition Starve 
    - Citizen Income 
    - Plaque
      - bool WasPlaque 
    - int AcrePrice
  - HungerDeathCount



- Statistics
  - Среднеегодовая смертность
  - Кол-во акров на жителя
  - результат-оценка
 



