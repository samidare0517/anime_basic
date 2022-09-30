#include "DxLib.h"
#include <cassert>
#include "SceneMain.h"

namespace
{
	// �O���t�B�b�N�t�@�C����
	const char* const kPlayerFraphicFilename = "data/char.png";

	// �v���C���[�O���t�B�b�N������
	constexpr int kPlayerFraphivcDivX = 3;
	constexpr int kPlayerFraphivcDivY = 4;
	constexpr int kPlayerFraphivcDivNum = kPlayerFraphivcDivX * kPlayerFraphivcDivY;

	// �v���C���[�O���t�B�b�N�T�C�Y
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

// ������
void SceneMain::init()
{
	LoadDivGraph(kPlayerFraphicFilename, kPlayerFraphivcDivNum, kPlayerFraphivcDivX, kPlayerFraphivcDivY, kPlayerFraphivcSizeX, kPlayerFraphivcSizeY, m_hPlayerGraphic);
	m_player.setHandle(m_hPlayerGraphic[4]);
	m_player.init();
}

// �I������
void SceneMain::end()
{
	for (auto& handle : m_hPlayerGraphic)
	{
		DeleteGraph(handle);
	}
}

// ���t���[���̏���
void SceneMain::update()
{
	m_player.update();
}

// ���t���[���̕`��
void SceneMain::draw()
{
	m_player.draw();
}