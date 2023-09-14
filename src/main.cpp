#include <iostream>
#include <mlpack/core.hpp>
#include <mlpack/methods/regression/regression.hpp>

using namespace mlpack;

int main()
{
    // Load your time series data.
    arma::mat timeSeriesData = {
        {1, 10},
        {2, 12},
        {3, 15},
        {4, 18},
        {5, 20},
        {6, 25},
        {7, 30},
        {8, 32},
        {9, 35},
        {10, 40}
    };// Make sure dt_periodo is a column in your data.

    // Split data into training and testing sets.
    size_t trainSize = 80; // 80% for training, adjust as needed.
    arma::mat trainingData = timeSeriesData.submat(0, 0, trainSize - 1, timeSeriesData.n_cols - 1);
    arma::mat testingData = timeSeriesData.submat(trainSize, 0, timeSeriesData.n_rows - 1, timeSeriesData.n_cols - 1);

    // Perform autoregressive modeling.
    size_t order = 1; // Example order, adjust as needed.
    regression::LinearRegression lr(trainingData, order);

    // Predict using the model.
    arma::rowvec predictions;
    lr.Predict(testingData, predictions);

    // Evaluate the model (e.g., using mean squared error).
    arma::rowvec actuals = testingData.row(order); // Assuming order is 1.
    double mse = arma::accu(arma::square(predictions - actuals)) / predictions.n_elem;
    std::cout << "Mean Squared Error: " << mse << std::endl;

    return 0;
}
