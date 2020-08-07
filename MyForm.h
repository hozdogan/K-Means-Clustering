#pragma once
#pragma once
#include<vector>
#include<stdlib.h>
#include <iostream>
#include <queue>
#include <time.h>
#include "Üst Bilgi.h"

namespace KMeansClustering {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm için özet
	/// </summary>
	std::vector<Point2D*> vecP;
	int cluster,index,x,y,cycle;
	std::vector<Renk> colorvec;
	std::vector<Sets*> vecS;
	Point2D* pat;
	Sets* kume;
	double* distances;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Oluþturucu kodunu buraya ekle
			//
		}

	protected:
		/// <summary>
		///Kullanýlan tüm kaynaklarý temizleyin.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ processToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ normalizationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ clusteringToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ hirerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ agglomerativeToolStripMenuItem;
	private: System::Windows::Forms::Button^ Set;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ToolStripMenuItem^ showGravityCentersToolStripMenuItem;


	private:
		/// <summary>
		///Gerekli tasarýmcý deðiþkeni.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Tasarýmcý desteði için gerekli metot - bu metodun 
		///içeriðini kod düzenleyici ile deðiþtirmeyin.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->processToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->normalizationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clusteringToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hirerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->agglomerativeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Set = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->showGravityCentersToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pictureBox1->Location = System::Drawing::Point(33, 39);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(500, 500);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseClick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->processToolStripMenuItem,
					this->hirerToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1131, 28);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// processToolStripMenuItem
			// 
			this->processToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->normalizationToolStripMenuItem,
					this->clusteringToolStripMenuItem, this->showGravityCentersToolStripMenuItem
			});
			this->processToolStripMenuItem->Name = L"processToolStripMenuItem";
			this->processToolStripMenuItem->Size = System::Drawing::Size(72, 24);
			this->processToolStripMenuItem->Text = L"Process";
			// 
			// normalizationToolStripMenuItem
			// 
			this->normalizationToolStripMenuItem->Name = L"normalizationToolStripMenuItem";
			this->normalizationToolStripMenuItem->Size = System::Drawing::Size(231, 26);
			this->normalizationToolStripMenuItem->Text = L"Normalization";
			this->normalizationToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::normalizationToolStripMenuItem_Click);
			// 
			// clusteringToolStripMenuItem
			// 
			this->clusteringToolStripMenuItem->Name = L"clusteringToolStripMenuItem";
			this->clusteringToolStripMenuItem->Size = System::Drawing::Size(231, 26);
			this->clusteringToolStripMenuItem->Text = L"Clustering";
			this->clusteringToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::clusteringToolStripMenuItem_Click);
			// 
			// hirerToolStripMenuItem
			// 
			this->hirerToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->agglomerativeToolStripMenuItem });
			this->hirerToolStripMenuItem->Name = L"hirerToolStripMenuItem";
			this->hirerToolStripMenuItem->Size = System::Drawing::Size(102, 24);
			this->hirerToolStripMenuItem->Text = L"Hierarchical";
			// 
			// agglomerativeToolStripMenuItem
			// 
			this->agglomerativeToolStripMenuItem->Name = L"agglomerativeToolStripMenuItem";
			this->agglomerativeToolStripMenuItem->Size = System::Drawing::Size(191, 26);
			this->agglomerativeToolStripMenuItem->Text = L"Agglomerative";
			// 
			// Set
			// 
			this->Set->Location = System::Drawing::Point(839, 150);
			this->Set->Name = L"Set";
			this->Set->Size = System::Drawing::Size(75, 23);
			this->Set->TabIndex = 2;
			this->Set->Text = L"Set";
			this->Set->UseVisualStyleBackColor = true;
			this->Set->Click += gcnew System::EventHandler(this, &MyForm::Set_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"1", L"2", L"3", L"4" });
			this->comboBox1->Location = System::Drawing::Point(815, 41);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(701, 44);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(93, 17);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Cluster Count";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(815, 92);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(121, 22);
			this->textBox1->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(701, 95);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 17);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Cycle";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(701, 156);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 17);
			this->label4->TabIndex = 8;
			this->label4->Text = L"label4";
			// 
			// showGravityCentersToolStripMenuItem
			// 
			this->showGravityCentersToolStripMenuItem->Name = L"showGravityCentersToolStripMenuItem";
			this->showGravityCentersToolStripMenuItem->Size = System::Drawing::Size(231, 26);
			this->showGravityCentersToolStripMenuItem->Text = L"Show Gravity Centers";
			this->showGravityCentersToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::showGravityCentersToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1131, 738);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->Set);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		void setInitialValues()
		{
			Renk r1(255, 0, 0);
			Renk r2(0, 0, 255);
			Renk r3(0, 255, 0);
			Renk r4(239, 163, 12);
			cluster = comboBox1->SelectedIndex + 1;
			cycle = (int)System::Convert::ToInt32(textBox1->Text->ToString());
			colorvec.push_back(r1);
			colorvec.push_back(r2);
			colorvec.push_back(r3);
			colorvec.push_back(r4);
			Graphics^ g = pictureBox1->CreateGraphics();
			Pen^ p = gcnew Pen(Color::Black, 3);
			g->DrawLine(p, 0, 250, 500, 250);
			g->DrawLine(p, 250, 0, 250, 500);
			distances = new double[cycle];

		}
#pragma endregion
	
private: System::Void clusteringToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	srand(time(NULL));
	ClassifiersProcess cs;
	int index;
	Point2D* p1;
	double* arr;
	double sumX = 0.0,sumY = 0.0,sumDistance = 0.0;
	for (int i = 0; i < cluster; i++)
	{
		kume = new Sets();
		vecS.push_back(kume);
	}
	arr = new double[vecS.size()];
	for (int d = 0; d < cycle; d++)
	{
		for (int i = 0; i < cluster; i++)
		{
			p1 = new Point2D((rand() % 501) - 250, (rand() % 501) - 250);
			vecS[i]->setTempMidPoint(p1);
			//MessageBox::Show(p1->getX().ToString() + " " + p1->getY().ToString());
		}//kumeler olusturuldu rastgele aðýrlýk merkezleri atandý
		for (int i = 0; i < vecP.size(); i++)
		{
			for (int j = 0; j < vecS.size(); j++)
			{
				arr[j] = cs.BTPLen(vecP[i], vecS[j]->getTempMidPoint());
			}
			index = cs.findMinIndex(arr, vecS.size());
			//vecP[i]->setClassID(index);
			vecS[index]->pb_point(vecP[i]);
		}//her nokta kendine yakýn kumeye eklendi

		//kumeler içinde yeniden aðýrlýk merkezlerinin hesaplanmasý
		for (int i = 0; i < vecS.size(); i++)
		{
			for (int j = 0; j < vecS[i]->getPointVecLength(); j++)
			{
				sumX += vecS[i]->getPoint(j)->getX();
				sumY += vecS[i]->getPoint(j)->getY();
			}
			vecS[i]->setMidpoint(new Point2D(sumX / vecS[i]->getPointVecLength(), sumY / vecS[i]->getPointVecLength()));
			vecS[i]->pb_cpoint(vecS[i]->getMidPoint());
			sumX = 0; sumY = 0;
			//cizim yapýlabilir
			for (int j = 0; j < vecS[i]->getPointVecLength(); j++)
			{
				sumDistance += cs.BTPLen(vecS[i]->getPoint(j), vecS[i]->getMidPoint());
			}//aðýrlýk merkezine göre uzaklýklarýn toplanýp kaydedilmesi
		}//her kümenin aðýrlýk merkezi yeniden hesaplandý sonra denemeler kaydedilecek
		distances[d] = sumDistance;
		sumDistance = 0;
		label4->Text = "Cycle:" + d.ToString();
		label4->Refresh();
		for (int i = 0; i < vecS.size(); i++)
		{
			vecS[i]->clearall();
		}
	}//algoritma n kere calýstý

	index = cs.findMinIndex(distances, cycle);
	for (int i = 0; i < vecS.size(); i++)
	{
		vecS[i]->setMidpoint(vecS[i]->getCenterPoint(index));
	}
	   //cycle kadar deneme sonucunda her kümenin en düþük uzaklýða sahip aðýrlýk merkezi atanmýþtýr.
	//sonra bu merkez baz alýnarak yeniden kümelere ait noktalar hesaplanýr ve etiket deðerleri atanýr.
	for (int i = 0; i < vecP.size(); i++)
	{
		for (int j = 0; j < vecS.size(); j++)
		{
			arr[j] = cs.BTPLen(vecP[i], vecS[j]->getMidPoint());
		}
		index = cs.findMinIndex(arr, vecS.size());
		vecP[i]->setClassID(index);
		vecS[index]->pb_point(vecP[i]);
	}//her nokta kendine yakýn kumeye eklendi
	//gerisi cizim
	Pen^ pen;
	int xx, yy;
	Graphics^ g = pictureBox1->CreateGraphics();
	for (int i = 0; i < vecP.size(); i++)
	{
		Color c = Color::FromArgb(colorvec[vecP[i]->getClassID()].getRed(), colorvec[vecP[i]->getClassID()].getGreen(), colorvec[vecP[i]->getClassID()].getBlue());
		pen = gcnew Pen(c, 2);
		xx = vecP[i]->getX() + pictureBox1->Width/2;
		yy = (pictureBox1->Height / 2)- vecP[i]->getY();
		g->DrawLine(pen, xx - 4, yy, xx + 4, yy);
		g->DrawLine(pen, xx, yy - 4, xx, yy + 4);
	}
	
}
private: System::Void pictureBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	Pen^ pen;
	Graphics^ g = pictureBox1->CreateGraphics();
	pen = gcnew Pen(Color::Black, 2);

	x = e->X - (pictureBox1->Width / 2);
	y = (pictureBox1->Height / 2) - e->Y;
	pat = new Point2D(x, y);
	//pat->setClassID(index);
	vecP.push_back(pat);
	//bunun yerine çemberde olabilir
	g->DrawLine(pen, e->X - 4, e->Y, e->X + 4, e->Y);
	g->DrawLine(pen, e->X, e->Y - 4, e->X, e->Y + 4);
}
private: System::Void Set_Click(System::Object^ sender, System::EventArgs^ e) {
	setInitialValues();
}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void normalizationToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void showGravityCentersToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Pen^ pen;
	Graphics^ g = pictureBox1->CreateGraphics();
	int xx, yy;
	for (int i = 0; i < vecS.size(); i++)
	{
		Color c = Color::FromArgb(colorvec[i].getRed(), colorvec[i].getGreen(), colorvec[i].getBlue());
		pen = gcnew Pen(c, 2);
		xx = vecS[i]->getMidPoint()->getX() + pictureBox1->Width / 2;
		yy = (pictureBox1->Height / 2) - vecS[i]->getMidPoint()->getY();
		g->DrawEllipse(pen, xx, yy, 10, 10);
	}
}
};
}
