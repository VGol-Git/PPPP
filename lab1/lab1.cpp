#include <iostream>
#include <cstdlib>
#include <ctime>

int startSizeColumnMatrix[2], startSizeRowMatrix[2], n2 = 1, m2 = 1, keyFilling, reducedMatrixSize = 2;

void CoutMatrix(int** Matrix, int indMatrix, int collumn, int rows) {
	std::cout << "\nМатрица " << indMatrix << " \n\n";
	for (int i = 0; i < collumn; i++)
	{
		for (int column = 0; column < rows; column++)
			std::cout << Matrix[i][column] << " ";
		std::cout << std::endl;
	}

}
void InitializationMatrix(int** Matrix, int indMatrix, int approachKey, int collumn, int rows) {
	for (int i = 0; i < collumn; i++)
		for (int column = 0; column < rows; column++)
			switch (approachKey) {
			case 1: std::cin >> Matrix[i][column]; break;//Ручной ввод 
			case 2: Matrix[i][column] = rand() % 10; //Случайный ввод
			}
}
void BringingToTheDesiredSize(int**& Matrix, int& collumn, int& rows) {
	int** newMatrix = new int*[reducedMatrixSize];
	for (int i = 0; i < reducedMatrixSize; i++) {
		newMatrix[i] = new int[reducedMatrixSize];
		for (int column = 0; column < reducedMatrixSize; column++)
			newMatrix[i][column] = 0;
	}
	//copy()
	for (int i = 0; i < collumn; i++)
	{
		for (int column = 0; column < rows; column++)
			newMatrix[i][column] = Matrix[i][column];
	}

	for (int i = 0; i < collumn; i++)
		delete[] Matrix[i];
	delete[] Matrix;

	Matrix = newMatrix;
	collumn = reducedMatrixSize;
	rows = reducedMatrixSize;
}
void SplittingOfTheMatrix(int**& splitMatrix, int**& Matrix, int shiftRow, int shiftColl) {
	for (int row = 0; row < reducedMatrixSize / 2; row++)
		for (int coll = 0; coll < reducedMatrixSize / 2; coll++)
			splitMatrix[row][coll] = Matrix[row + shiftRow][coll + shiftColl];
}
void AddRowsToMatrix(int**& Matrix, int  sizeRows, int sizeColomns) {
	for (int i = 0; i < sizeRows; i++)
		Matrix[i] = new int[sizeColomns];
}
void AddMatrixsToMatrix(int***& MainMatrix, int sizeMatrix, int sizeRows, int sizeColomns) { // MainMatrix  - это матрица матриц
	for (int i = 0; i < sizeMatrix; i++)
	{
		MainMatrix[i] = new int*[sizeRows];
		AddRowsToMatrix(MainMatrix[i], sizeRows, sizeColomns);
	}
}

void CalculatingMediateMatrix1(int**& mediateMatrix, int** &SplitMatrix1, int** &SplitMatrix2, int** &SplitMatrix3, int** &SplitMatrix4) {
	for (int i = 0; i < reducedMatrixSize / 2; i++) {
		for (int column = 0; column < reducedMatrixSize / 2; column++) {
			mediateMatrix[i][column] = 0;
			for (int z = 0; z < reducedMatrixSize / 2; z++) {
				mediateMatrix[i][column] += (SplitMatrix1[i][z] + SplitMatrix2[i][z]) * (SplitMatrix3[z][column] + SplitMatrix4[z][column]);
			}
		}
	}
}
void CalculatingMediateMatrix2(int**& mediateMatrix, int** &SplitMatrix1, int** &SplitMatrix2, int** &SplitMatrix3) {
	for (int i = 0; i < reducedMatrixSize / 2; i++)
	{
		for (int column = 0; column < reducedMatrixSize / 2; column++)
		{
			mediateMatrix[i][column] = 0;
			for (int z = 0; z < reducedMatrixSize / 2; z++)
			{
				mediateMatrix[i][column] += (SplitMatrix1[i][z] + SplitMatrix2[i][z]) * SplitMatrix3[z][column];
			}
		}
	}
}
void CalculatingMediateMatrix3(int**& mediateMatrix, int** &SplitMatrix1, int** &SplitMatrix2, int** &SplitMatrix3) {
	for (int i = 0; i < reducedMatrixSize / 2; i++) {
		for (int column = 0; column < reducedMatrixSize / 2; column++) {
			mediateMatrix[i][column] = 0;
			for (int z = 0; z < reducedMatrixSize / 2; z++) {
				mediateMatrix[i][column] += SplitMatrix1[i][z] * (SplitMatrix2[z][column] - SplitMatrix3[z][column]);
			}

		}
	}

}
void CalculatingMediateMatrix4(int**& mediateMatrix, int** &SplitMatrix1, int** &SplitMatrix2, int** &SplitMatrix3, int** &SplitMatrix4) {
	for (int i = 0; i < reducedMatrixSize / 2; i++) {
		for (int column = 0; column < reducedMatrixSize / 2; column++) {
			mediateMatrix[i][column] = 0;
			for (int z = 0; z < reducedMatrixSize / 2; z++) {
				mediateMatrix[i][column] += (SplitMatrix1[i][z] - SplitMatrix2[i][z]) * (SplitMatrix3[z][column] + SplitMatrix4[z][column]);
			}
		}
	}
}

void CalculatingAuxiliaryMatrix1(int**& AuxiliaryMatrix, int***& MediateMatrices, int row, int column) {
	AuxiliaryMatrix[row][column] = MediateMatrices[0][row][column] + MediateMatrices[3][row][column] - MediateMatrices[4][row][column] + MediateMatrices[6][row][column];
}
void CalculatingAuxiliaryMatrix2(int**& AuxiliaryMatrix, int***& MediateMatrices, int row, int column) {
	AuxiliaryMatrix[row][column] = MediateMatrices[2][row][column] + MediateMatrices[4][row][column];
}
void CalculatingAuxiliaryMatrix3(int**& AuxiliaryMatrix, int***& MediateMatrices, int row, int column) {
	AuxiliaryMatrix[row][column] = MediateMatrices[1][row][column] + MediateMatrices[3][row][column];
}
void CalculatingAuxiliaryMatrix4(int**& AuxiliaryMatrix, int***& MediateMatrices, int row, int column) {
	AuxiliaryMatrix[row][column] = MediateMatrices[0][row][column] + MediateMatrices[2][row][column] - MediateMatrices[1][row][column] + MediateMatrices[5][row][column];
}

void alignmentMatrix(int **& Matrix, int& alignment, int row, int column) {
	for (row = 0; row < reducedMatrixSize; row++) {
		int valuesZero = 0;
		for (column = 0; column < reducedMatrixSize; column++)
			Matrix[row][column] ? valuesZero++ : alignment = 100;

		if (!valuesZero && row < alignment)
			alignment = row;
	}
}
//
//void matrixMatrices(int ***& Matrix, int sizeMatrix) {
//	for (int i = 0; i < sizeMatrix; i++) 
//		deleteMatrix
//}
void deleteMatrix(int **& Matrix , int sizeRows) {
	for (int i = 0; i < sizeRows; i++) {
			delete[] Matrix[i];
	}
		delete[] Matrix;
}

int main()
{
	srand(time(NULL));
	system("chcp 1251");
	std::cout << "Вас приветствует программа" << std::endl <<
	//Ввод размеров матрицы пользователем
		"быстрого перемножения матриц методом Штрассена\n\n";
	for (int i = 0; i < 2; i++) {
		do
		{
			std::cout << "Введите размеры " << (!i ? "первой " : " второй ") << "матрицы\n";
			std::cin >> startSizeColumnMatrix[i] >> startSizeRowMatrix[i];
		} while (startSizeColumnMatrix[i] <= 0 || startSizeRowMatrix[i] <= 0);
	}
	//AddMatrixsToMatrix(StartMatrixs, 2, n1, m1);
	//Выбор способа заполнения и заполнение матриц
	do
	{
		std::cout << "Выберите способ заполнения матриц\n" <<
			"1 - Вручную \n2 - Случайным образом\n";
		std::cin >> keyFilling;
	} while (keyFilling < 1 || keyFilling > 2);

	int*** StartMatrixs = new int**[2];
	for (int i = 0; i < 2; i++) {
		StartMatrixs[i] = new int*[startSizeColumnMatrix[i]];
		AddRowsToMatrix(StartMatrixs[i], startSizeColumnMatrix[i], startSizeRowMatrix[i]);
		InitializationMatrix(StartMatrixs[i], i + 1, keyFilling, startSizeColumnMatrix[i], startSizeRowMatrix[i]);
	}
	for (int i = 0; i < 2; i++)
		CoutMatrix(StartMatrixs[i], i + 1, startSizeColumnMatrix[i], startSizeRowMatrix[i]);
	//Приведение матриц к требуемому размеру

	while (reducedMatrixSize < startSizeColumnMatrix[0] || reducedMatrixSize < startSizeColumnMatrix[1] || reducedMatrixSize < startSizeRowMatrix[0] || reducedMatrixSize < startSizeRowMatrix[1])
		reducedMatrixSize *= 2;
	std::cout << "Приведенные матрицы\n";
	for (int i = 0; i < 2; i++)
	{
		BringingToTheDesiredSize(StartMatrixs[i], startSizeColumnMatrix[i], startSizeRowMatrix[i]);
		CoutMatrix(StartMatrixs[i], i + 1, startSizeColumnMatrix[i], startSizeRowMatrix[i]);
	}
	//Разбиение матриц на подматрицы и их заполнение
	int*** SplitMatrix1 = new int**[4];
	int*** SplitMatrix2 = new int**[4];
	AddMatrixsToMatrix(SplitMatrix1, 4, reducedMatrixSize / 2, reducedMatrixSize / 2);
	AddMatrixsToMatrix(SplitMatrix2, 4, reducedMatrixSize / 2, reducedMatrixSize / 2);
	int MatrixCount = 0;

	for (int column = 0; column < reducedMatrixSize; column += reducedMatrixSize / 2)
		for (int i = 0; i < reducedMatrixSize; i += reducedMatrixSize / 2)
		{
			SplittingOfTheMatrix(SplitMatrix1[MatrixCount], StartMatrixs[0], column, i);
			SplittingOfTheMatrix(SplitMatrix2[MatrixCount], StartMatrixs[1], column, i);
			MatrixCount++;
		}
	//Создание промежуточных матриц
	int*** MediateMatrix = new int**[7];
	AddMatrixsToMatrix(MediateMatrix, 7, reducedMatrixSize / 2, reducedMatrixSize / 2);
	//Вычисление значений промежуточных матриц
	CalculatingMediateMatrix1(MediateMatrix[0], SplitMatrix1[0], SplitMatrix1[3], SplitMatrix2[0], SplitMatrix2[3]);
	CalculatingMediateMatrix2(MediateMatrix[1], SplitMatrix1[2], SplitMatrix1[3], SplitMatrix2[0]);
	CalculatingMediateMatrix3(MediateMatrix[2], SplitMatrix1[0], SplitMatrix2[1], SplitMatrix2[3]);
	CalculatingMediateMatrix3(MediateMatrix[3], SplitMatrix1[3], SplitMatrix2[2], SplitMatrix2[0]);
	CalculatingMediateMatrix2(MediateMatrix[4], SplitMatrix1[0], SplitMatrix1[1], SplitMatrix2[3]);
	CalculatingMediateMatrix4(MediateMatrix[5], SplitMatrix1[2], SplitMatrix1[0], SplitMatrix2[0], SplitMatrix2[1]);
	CalculatingMediateMatrix4(MediateMatrix[6], SplitMatrix1[1], SplitMatrix1[3], SplitMatrix2[2], SplitMatrix2[3]);
	//Создание вспомогательных матриц
	int*** AuxiliaryMatrices = new int**[4];
	AddMatrixsToMatrix(AuxiliaryMatrices, 4, reducedMatrixSize / 2, reducedMatrixSize / 2);

	//Подсчет значений вспомогательных матриц из промежуточных
	for (int i = 0; i < reducedMatrixSize / 2; i++) {
		for (int column = 0; column < reducedMatrixSize / 2; column++) {
			CalculatingAuxiliaryMatrix1(AuxiliaryMatrices[0], MediateMatrix, i, column);
			CalculatingAuxiliaryMatrix2(AuxiliaryMatrices[1], MediateMatrix, i, column);
			CalculatingAuxiliaryMatrix3(AuxiliaryMatrices[2], MediateMatrix, i, column);
			CalculatingAuxiliaryMatrix4(AuxiliaryMatrices[3], MediateMatrix, i, column);
		}
	}
	//Создание результирующей матрицы
	int** ResultMatrix = new int*[reducedMatrixSize];
	AddRowsToMatrix(ResultMatrix, reducedMatrixSize, reducedMatrixSize);
	//Занесение информации из вспомогательных матриц в результирующую
	for (int i = 0; i < reducedMatrixSize / 2; i++) {
		for (int column = 0; column < reducedMatrixSize / 2; column++) {
			ResultMatrix[i][column] = AuxiliaryMatrices[0][i][column];
			ResultMatrix[i][column + reducedMatrixSize / 2] = AuxiliaryMatrices[1][i][column];
			ResultMatrix[i + reducedMatrixSize / 2][column] = AuxiliaryMatrices[2][i][column];
			ResultMatrix[i + reducedMatrixSize / 2][column + reducedMatrixSize / 2] = AuxiliaryMatrices[3][i][column];
		}
	}

	//Выравнивание границ результирующей матрицы
	int f = 100, s = 100, row = 0, column = 0;
	alignmentMatrix(ResultMatrix, f, row, column); //по столбцам
	alignmentMatrix(ResultMatrix, s, column, row); //по строкам
   //Вывод результирующей матрицы
	std::cout << "\nРезультирующая матрица\n\n";
	CoutMatrix(ResultMatrix, 0, f, s);	//Очистка динамической памяти
	for (int i = 0; i < 2; i++)
		deleteMatrix(StartMatrixs[i], startSizeColumnMatrix[i]);
	for (int i = 0; i < 7; i++)
		deleteMatrix(MediateMatrix[i], reducedMatrixSize/2);
	for (int i = 0; i < 4; i++) {
		deleteMatrix(SplitMatrix1[i], reducedMatrixSize / 2);
		deleteMatrix(SplitMatrix2[i], reducedMatrixSize / 2);
		deleteMatrix(AuxiliaryMatrices[i], reducedMatrixSize / 2);
	}
	deleteMatrix(ResultMatrix, reducedMatrixSize);
	delete[] StartMatrixs, MediateMatrix, SplitMatrix1, SplitMatrix2, AuxiliaryMatrices;
}