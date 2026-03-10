#include "pch.h"
#include <cmath>

float* Add_Data(float* sample, int Size, float* x, int Dim) {
	float* temp = new float[Size * Dim];
	for (int i = 0; i < (Size - 1) * Dim; i++)
		temp[i] = sample[i];
	for (int i = 0; i < Dim; i++)
		temp[(Size - 1) * Dim + i] = x[i];
	//Deallocate memory
	delete[] sample;
	return temp;
}//Add_data
float* Add_Labels(float* Labels, int Size, int label) {
	float* temp = new float[Size];
	for (int i = 0; i < Size - 1; i++)
		temp[i] = Labels[i];
	temp[Size - 1] = float(label);
	//Deallocate memory
	delete[] Labels;
	return temp;
}
float* init_array_random(int len) {
	float* arr = new float[len];
	for (int i = 0; i < len; i++)
		arr[i] = ((float)rand() / RAND_MAX) - 0.5f;
	return arr;
}
void Z_Score_Parameters(float* x, int Size, int dim, float* mean, float* std) {

	float* Total = new float[dim];

	int i, j;
	for (i = 0; i < dim; i++) {
		mean[i] = std[i] = Total[i] = 0.0;
	}
	for (i = 0; i < Size; i++)
		for (j = 0; j < dim; j++)
			Total[j] += x[i * dim + j];
	for (i = 0; i < dim; i++)
		mean[i] = Total[i] / float(Size);

	for (i = 0; i < Size; i++)
		for (j = 0; j < dim; j++)
			std[j] += ((x[i * dim + j] - mean[j]) * (x[i * dim + j] - mean[j]));

	for (j = 0; j < dim; j++)
		std[j] = sqrt(std[j] / float(Size));

	delete[] Total;

}//Z_Score_Parameters
int Test_Forward(float* sample, float* Weights, float* bias, int layer, int* neuron_count, int inputDim) {

	int** sums = new int* [layer + 1] {0};//Bu o layer'a kadarki toplam nöron ve weight sayýsýný tutuyor(0 = noron sayýsý, 1 = weight sayýsý)
	for (int i = 0; i <= layer; i++)
	{
		sums[i] = new int[2] {0, 0};
	}

	for (int i = 0; i < layer; i++)
	{
		int current_layer_weights = 0;

		if (i == 0) current_layer_weights = inputDim * neuron_count[i];
		else current_layer_weights = neuron_count[i - 1] * neuron_count[i];

		sums[i + 1][1] += sums[i][1] + current_layer_weights; //weightSum
		sums[i + 1][0] += sums[i][0] + neuron_count[i];//neuronSum
	}

	float* f_net = new float[sums[layer][0]];

	//Forward
	for (int l = 0; l < layer; l++)
	{
		for (int k = 0; k < neuron_count[l]; k++)
		{
			float sum = 0.0f;
			if (l == 0)
			{
				for (int i = 0; i < inputDim; i++)
				{
					sum += Weights[sums[l][1] + k * inputDim + i] * sample[i];
				}
			}
			else
			{
				for (int i = 0; i < neuron_count[l - 1]; i++)//-1 almamýzýn sebebi ilk yerde inputDim i kullanýyor olmamýz.
				{
					sum += Weights[sums[l][1] + k * neuron_count[l - 1] + i] * f_net[sums[l - 1][0] + i];
				}
			}
			sum+= bias[sums[l][0] + k];

			//Bipolar Sigmoid aktivasyon
			f_net[sums[l][0] + k] = (2.0f / (1 + System::Math::Exp(-sum))) - 1;
		}
	}

	int index_Max = 0;
	float max_score = -9999.0f;

	for (int i = 0; i < neuron_count[layer - 1]; i++)
	{
		if (f_net[sums[layer - 1][0] + i] > max_score) {
			max_score = f_net[sums[layer - 1][0] + i];
			index_Max = i;
		}
	}

	delete[] f_net;
	for (int i = 0; i <= layer; i++) delete[] sums[i];
	delete[] sums;

	return index_Max;

}

float Regression(float* sample, float* Weights, float* bias, int layer, int* neuron_count, int inputDim) {

	int** sums = new int* [layer + 1] {0};//Bu o layer'a kadarki toplam nöron ve weight sayýsýný tutuyor(0 = noron sayýsý, 1 = weight sayýsý)
	for (int i = 0; i <= layer; i++)
	{
		sums[i] = new int[2] {0, 0};
	}

	for (int i = 0; i < layer; i++)
	{
		int current_layer_weights = 0;

		if (i == 0) current_layer_weights = inputDim * neuron_count[i];
		else current_layer_weights = neuron_count[i - 1] * neuron_count[i];

		sums[i + 1][1] += sums[i][1] + current_layer_weights; //weightSum
		sums[i + 1][0] += sums[i][0] + neuron_count[i];//neuronSum
	}

	float* f_net = new float[sums[layer][0]];

	for (int i = 0; i < sums[layer][0]; i++)
		f_net[i] = 0;

	//Forward
	for (int l = 0; l < layer; l++)
	{
		for (int k = 0; k < neuron_count[l]; k++)
		{
			float sum = 0.0f;
			if (l == 0)
			{
				for (int i = 0; i < inputDim; i++)
					sum += Weights[sums[l][1] + k * inputDim + i] * sample[i];
			}
			else
			{
				for (int i = 0; i < neuron_count[l - 1]; i++)//-1 almamýzýn sebebi ilk yerde inputDim i kullanýyor olmamýz.
				{
					sum += Weights[sums[l][1] + k * neuron_count[l - 1] + i] * f_net[sums[l - 1][0] + i];
				}
			}
			sum += bias[sums[l][0] + k];

			if (l == layer - 1)
				f_net[sums[l][0] + k] = sum;
			else
				f_net[sums[l][0] + k] = (2.0f / (1 + System::Math::Exp(-sum))) - 1;
		}
	}

	float output = f_net[sums[layer - 1][0]];

	delete[] f_net;
	for (int i = 0; i <= layer; i++) delete[] sums[i];
	delete[] sums;

	return output;

}