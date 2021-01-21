<p>介紹 : 這是資料結構課程project_3，製作的棋類競技遊戲，用C++寫，有多個.cpp檔，主要為Algorithm.cpp。遊戲規則很特別，主要是雙人對戰，自己的棋子最先佔滿棋盤的為贏家。<p>
<p>規則 : 5*6棋盤，雙方輪流下一顆棋，同一格可同時有多顆棋子，但雙方棋子不可再同一格。當同一格中棋子數=周圍格子數，該格子清空，周圍所有格子+1顆棋子，且棋子顏色變為我方。<p>
<p>實作 : 我設計一張5*6加權表，紀錄所有格子的加權值，而我分成6種狀況，並各別賦予不同加權值，若下一步下該格的話愈容易贏，則加權值愈高。最後選擇最高的作為下一步棋。<p>
<p>附上Algorithm.cpp和詳細report。<p>
