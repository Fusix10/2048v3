#include "Table.h";
#include "Case.h";
#include "Random.h";
#include <time.h>;
#include <Windows.h>;

Table::Table(int size)
{
	std::cout << "taille du tableau: \n";
	std::cout << "taille classique : 4 \n";
	std::cin >> size;
	Table2048.resize(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			Table2048[i].push_back(a);
			Table2048[i][j].x = i;
			Table2048[i][j].y = j;
		}
	}
	WhiteList();
};

void Table::WhiteList() 
{
	StorageCase.clear();
	StorageCase.resize(Table2048.size() * Table2048.size());
	int w = 0;
	for (int i = 0; i < Table2048.size(); i++)
	{
		for (int j = 0; j < Table2048.size(); j++)
		{
			if (Table2048[i][j].Number == 0) {
				StorageCase[w + j] = Table2048[i][j];
			}
		}
		w += Table2048.size();
	}
}

void Table::draw()
{
	for (int i = 0; i < Table2048.size(); i++)
	{
		SetConsoleTextAttribute(hConsole, 4);
		std::cout << "[" << "i" << i << "]";
		for (int j = 0; j < Table2048.size(); j++)
		{
			SetConsoleTextAttribute(hConsole, 7);
			std::cout << "[" << Table2048[i][j].Number << " ]";
		}
		std::cout << "\n";
		
	}
	SetConsoleTextAttribute(hConsole, 4);
	std::cout << "[" << "  " << "]";
	for (int j = 0; j < Table2048.size(); j++)
	{
		std::cout << "[" << "j" << j << "]";;
	}
	SetConsoleTextAttribute(hConsole, 7);
};

void Table::Dispatche() 
{
	int Who = b.MtdRan(StorageCase.size());
	Table2048[StorageCase[Who].x][StorageCase[Who].y].SetRandom();
	WhiteList();
}

void Table::Deplacement(int Direction) {
	/*
	*  1 = a gauche
	*  2 = en haut
	*  3 = a droite
	*  4 = en bas
	*/
	if (Direction == 1) {
		for (int i = 0; i < Table2048.size(); i++) {
			for (int j = 0; j < Table2048.size(); j++) {
				if (Table2048[i][j].Number == 0) {
					continue;
				}
				else {
					if (j == 0) {
						continue;
					}
					else
					{
						for(int w = j-1; w >= 0; --w){
							if (w == 0) {
								if (Table2048[i][w].Number == 0) {
									if (w + 1 != j) {
										Table2048[i][0].Number = Table2048[i][j].Number;
										Table2048[i][j].Number = 0;
										break;
									}
									else {
										break;
									}
								}
								else {
									std::cout << "[" << "Probleme: 01 voir code Table.cpp" << " ]";
									//le code fonctionne pas donc si tu voie sa mec call me DIRECTE
								}
							}
							else {
								if (Table2048[i][w].Number == 0) {
									continue;
								}
								else {
									if (w + 1 != j) {
										Table2048[i][w + 1].Number = Table2048[i][j].Number;
										Table2048[i][j].Number = 0;
									}
									else {
										break;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	else if (Direction == 2) {
		for (int i = 0; i < Table2048.size(); i++) {
			for (int j = 0; j < Table2048.size(); j++) {
				if (Table2048[j][i].Number == 0) {
					continue;
				}
				else {
					if (j == 0) {
						continue;
					}
					else
					{
						for (int w = j - 1; w >= 0; --w) {
							if (w == 0) {
								if (Table2048[i][w].Number == 0) {
									if (w + 1 != j) {
										Table2048[0][i].Number = Table2048[j][i].Number;
										Table2048[j][i].Number = 0;
										break;
									}
									else {
										break;
									}
								}
								else {
									std::cout << "[" << "Probleme: 01 voir code Table.cpp" << " ]";
									//le code fonctionne pas donc si tu voie sa mec call me DIRECTE
								}
							}
							else {
								if (Table2048[w][i].Number == 0) {
									continue;
								}
								else {
									if (w + 1 != j) {
										Table2048[w + 1][i].Number = Table2048[j][i].Number;
										Table2048[j][i].Number = 0;
									}
									else {
										break;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	else if (Direction == 3) {
		for (int i = 0; i < Table2048.size(); i++) {
			for (int j = Table2048.size() - 1; j >= 0; --j) {
				if (Table2048[i][j].Number == 0) {
					continue;
				}
				else {
					if (j == Table2048.size() - 1) {
						continue;
					}
					else
					{
						for (int w = j + 1; w < Table2048.size(); w++) {
							if (w == Table2048.size()) {
								if (Table2048[i][w].Number == 0) {
									if (w - 1 != j) {
										Table2048[i][0].Number = Table2048[i][j].Number;
										Table2048[i][j].Number = 0;
										break;
									}
									else {
										break;
									}
								}
								else {
									std::cout << "[" << "Probleme: 01 voir code Table.cpp" << " ]";
									//le code fonctionne pas donc si tu voie sa mec call me DIRECTE
								}
							}
							else {
								if (Table2048[i][w].Number == 0) {
									continue;
								}
								else {
									if (w - 1 != j) {
										Table2048[i][w - 1].Number = Table2048[i][j].Number;
										Table2048[i][j].Number = 0;
									}
									else {
										break;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	else if (Direction == 4) {
		for (int i = 0; i < Table2048.size(); i++) {
			for (int j = Table2048.size() - 1; j >= 0; --j) {
				if (Table2048[j][i].Number == 0) {
					continue;
				}
				else {
					if (j == Table2048.size() - 1) {
						continue;
					}
					else
					{
						for (int w = j + 1; w < Table2048.size(); w++) {
							if (w == Table2048.size()) {
								if (Table2048[w][i].Number == 0) {
									if (w - 1 != j) {
										Table2048[i][0].Number = Table2048[j][i].Number;
										Table2048[j][i].Number = 0;
										break;
									}
									else {
										break;
									}
								}
								else {
									std::cout << "[" << "Probleme: 01 voir code Table.cpp" << " ]";
									//le code fonctionne pas donc si tu voie sa mec call me DIRECTE
								}
							}
							else {
								if (Table2048[w][i].Number == 0) {
									continue;
								}
								else {
									if (w - 1 != j) {
										Table2048[w - 1][i].Number = Table2048[j][i].Number;
										Table2048[j][i].Number = 0;
									}
									else {
										break;
									}
								}
							}
						}
					}
				}
			}
		}
	}
};

void Table::Fusion(int Direction) {
	if (Direction == 1) {
		for (int i = 0; i < Table2048.size(); i++) {
			for (int j = 0; j < Table2048.size(); j++) {
				if (j != 0) {
					if (Table2048[i][j].Number != 0) {
						if (Table2048[i][j - 1].Number == Table2048[i][j].Number) {
							Table2048[i][j - 1].Number += Table2048[i][j].Number;
							Table2048[i][j].Number = 0;
						}
					}
				}
				else {
					continue;
				}
			}
		}
	}
	else if (Direction == 2) {
		for (int i = 0; i < Table2048.size(); i++) {
			for (int j = 0; j < Table2048.size(); j++) {
				if (j != 0) {
					if (Table2048[j][i].Number != 0) {
						if (Table2048[j - 1][i].Number == Table2048[j][j].Number) {
							Table2048[j - 1][i].Number += Table2048[j][i].Number;
							Table2048[j][i].Number = 0;
						}
					}
				}
				else {
					continue;
				}
			}
		}
	}
	else if (Direction == 3) {
		for (int i = 0; i < Table2048.size(); i++) {
			for (int j = Table2048.size() - 1; j >= 0; --j) {
				if (j != Table2048.size() + 1) {
					if (Table2048[i][j].Number != 0) {
						if (Table2048[i][j + 1].Number == Table2048[i][j].Number) {
							Table2048[i][j + 1].Number += Table2048[i][j].Number;
							Table2048[i][j].Number = 0;
						}
					}
				}
				else {
					continue;
				}
			}
		}
	}
	else if (Direction == 4) {
		for (int i = 0; i < Table2048.size(); i++) {
			for (int j = Table2048.size() - 1; j >= 0; --j) {
				if (j != Table2048.size() + 1) {
					if (Table2048[j][i].Number != 0) {
						if (Table2048[j + 1][i].Number == Table2048[j + 1][i].Number) {
							Table2048[j + 1][i].Number += Table2048[j + 1][i].Number;
							Table2048[j][i].Number = 0;
						}
					}
				}
				else {
					continue;
				}
			}
		}
	}
}