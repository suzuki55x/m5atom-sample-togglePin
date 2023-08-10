# m5atom-sample-togglePin

PPK2のロジアナ検証用。

G21を1[sec]ごとにHigh/Lowトグルするだけ。  
High/Lowに同期して、LEDも点滅させる。  
コア0で実行させるために、タスクを生成する。

G25はボタンを押すたびにトグルする。  
メインループのため、コア1で動く。
