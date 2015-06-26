# Face-Recognition
題目發想緣起

	由於進出學校創新開放實驗室(Moli)的人很多，但鑰匙卻只有寥寥幾隻在少數人手上。沒有鑰匙的人若是在沒有人的狀況下想進實驗室，就只能尋求鑰匙擁有者的幫忙，而這樣的過程其實很麻煩又很耗時還會消耗人與人之間的感情。而宿舍的指紋辨識門禁系統，也讓許多學生們曾經在半夜被關在宿舍門外，只因為一直無法辨識成功...。為了不要重複宿舍門禁系統的錯誤，我們想實作人臉辨識的門禁系統，但由於實作難度較高，目前僅做到人臉的偵測！

實作所需材料

	攝像頭*1(moli的->免費)
	pi2(感謝BT大大出借)
    
使用的現有軟體與來源

	語言:C++
	OpenCV
	
實作過程（碰到哪些問題、如何解決）
	
	剛開始試圖用javacv，但它沒有documentation，也不支援人臉辨識，只支援偵測，而當初就是以人臉辨識為目標，故只能放棄javacv。而emgucv支援人臉辨識但是不支援ip camera，但moli的就是ip camera，所以也只能放棄。
	最後才選擇使用opencv搭配C++!

操作教學（做出此產品之後該如何操作）

	程式安裝好就好了!看是要用usb camera或是ip camera都可以!

工作分配表

	coding 龍哥
	其他雜事 孟芫

參考來源

http://ccw1986.blogspot.tw/2013/09/learningopencv.html
http://ccw1986.blogspot.tw/2013/06/opencvfacerecognizer.html
http://ff320232.blogspot.tw/2013/06/opencv-face-detection.html
