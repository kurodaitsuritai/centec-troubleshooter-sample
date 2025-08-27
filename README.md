# centec-troubleshooter-sample
センテック社製 - USB troubleshooter lite(CT-USB1HUB-L)のON/OFFサンプル

## 注意

* 32bitでしか動作しない（提供されているDLLが32bit版のため）

* 動作には古いランタイムが必要。（[ここからダウンロード可能](https://www.microsoft.com/ja-jp/download/details.aspx?id=26999 "Microsoft Visual C++ 2010 Service Pack 1 再頒布可能パッケージ MFC のセキュリティ更新プログラム")）

* [参考](https://www.century.co.jp/products/ct-usb1hub-l.html "USB troubleshooter lite (CT-USB1HUB-L)")

* PC起動時には自動的にONになってしまうため、タスクスケジューラ等の使用が必要になる可能性もある。

## 使い方

※ONにする場合

```
centech-troubleshooter.exe 1
```

※OFFにする場合

```
centech-troubleshooter.exe 0
```
