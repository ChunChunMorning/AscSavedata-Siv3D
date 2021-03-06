﻿# include <Siv3D.hpp>
# include "asc/AscSavedata.hpp"

void Main()
{
	// セーブデータの作成
	asc::Savedata savedata(AES128Key(12, 34, 56, 78));

	// キーを追加する
	savedata.add(L"name", L"asachun");
	savedata.add(L"pos", Point(100, 100));
	savedata.add(L"hp", 100);

	// データをセーブ
	savedata.save(L"Asablo/Savedata.bin");

	WaitKey();

	// データをロード
	savedata.load();

	// 値の取り出し
	Println(savedata.get<String>(L"name"));
	Println(savedata.get<Point>(L"pos"));

	// キーの削除
	savedata.erase(L"hp");

	WaitKey();
}
