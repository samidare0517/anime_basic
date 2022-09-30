#include "DxLib.h"
#include <cassert>
#include "SceneMain.h"

namespace
{
	// グラフィックファイル名
	const char* const kPlayerFraphicFilename = "data/char.png";

	// プレイヤーグラフィック分割数
	constexpr int kPlayerFraphivcDivX = 3;
	constexpr int kPlayerFraphivcDivY = 4;
	constexpr int kPlayerFraphivcDivNum = kPlayerFraphivcDivX * kPlayerFraphivcDivY;

	// プレイヤーグラフィックサイズ
	constexpr int kPlayerFraphivcSizeX = 32;
	constexpr int kPlayerFraphivcSizeY = 32;
}



SceneMain::SceneMain()
{
	for (auto& handle : m_hPlayerGraphic)
	{
		handle = -1;
	}
}


SceneMain::~SceneMain()
{

}

// 初期化
void SceneMain::init()
{
	LoadDivGraph(kPlayerFraphicFilename, kPlayerFraphivcDivNum, kPlayerFraphivcDivX, kPlayerFraphivcDivY, kPlayerFraphivcSizeX, kPlayerFraphivcSizeY, m_hPlayerGraphic);
	m_player.setHandle(m_hPlayerGraphic[4]);
	m_player.init();
}

// 終了処理
void SceneMain::end()
{
	for (auto& handle : m_hPlayerGraphic)
	{
		DeleteGraph(handle);
	}
}

// 毎フレームの処理
void SceneMain::update()
{
	m_player.update();
}

// 毎フレームの描画
void SceneMain::draw()
{
	m_player.draw();
}