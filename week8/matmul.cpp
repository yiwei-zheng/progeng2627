#include <iostream>
#include <string>
#include <fstream> 
#include <vector>  
#include <iomanip>
#include <sstream>

#define Matrix std::vector<std::vector<double>>
#define VectorArray std::vector<std::vector<double>>
#define dVector std::vector<double>

std::vector<double> line_to_vector(std::string s){

    std::stringstream ss;
    std::string tmp;
    std::vector<double> out;

    // we can use a stringstream as if it were a stream object 
    // such as std::cout or something of type
    // std::ifstream or std::ofstream

    ss << s;
    while(ss >> tmp){
        // std::stod converts from string to double
        out.push_back(std::stod(tmp));
    }
    return out;
}

std::vector<std::vector<double>> read_matrix_from_file(std::string input_file){

    std::ifstream infile;
    infile.open(input_file);
    if(!infile.is_open()){
        std::cout << "error opening file " << input_file << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::string line;
    std::vector<std::vector<double>> out;

    // std::getline reads a whole line as a string
    // by default the separator is the newline
    // rather than any whitespace
    while(std::getline(infile, line)){
        out.push_back(line_to_vector(line));
    }

    return out;
}

std::string matrix_to_string(std::vector<std::vector<double>> m){

    std::stringstream out;
    // to set precision when printing
    out << std::fixed << std::setprecision(2);

    for(int i = 0; i < m.size(); i++){
        for(int j = 0; j < m[0].size(); j++){
            out << (m[i][j]) << "\t";
        }
        out << "\n";
    }

    // getting the std::string representation 
    // of this std::stringstream object
    return out.str();
}



Matrix zero_mat(int a, int b){
    Matrix mat;
    std::vector<double> line;
    for (int i = 0; i < b;i++){
        line.push_back(0);
    }
    for (int i = 0; i < a;i++){
        mat.push_back(line);
    }
    return mat;
}

double dproduct(const dVector& a, const dVector& b){
    int size = a.size();
    if(a.size() != b.size()){
        std::cout << "error in processing dot product\n";
        return -1;
    }
    double p;
    for (int i = 0; i < size;i++){
        p += a[i] * b[i];
    }
    return p;
}

int get_mat_dim(Matrix m, int dim){
    if(dim == 0){
        return m.size();
    }
    if(dim == 1){
        return m[0].size();
    }
    return -1;
}

VectorArray extract_vec(Matrix A, int dim){
    // if dim is 0, we get line vectors
    // if dim is 1, we get column vectors
    VectorArray arr = zero_mat(get_mat_dim(A, 1), get_mat_dim(A, 0));
    if (dim == 0){
        return A;
    }
    std::vector<double> vec;
    // like making a transpose of A
    for (int i = 0; i < get_mat_dim(A, 0); i++){
        for (int j = 0; j < get_mat_dim(A, 1);j++){
            arr[j][i] = A[i][j];
        }
    }
    return arr;
}



Matrix multiply(Matrix A, Matrix B){
    Matrix Y;
    if(get_mat_dim(A, 1) != get_mat_dim(B, 0)){
        std::cout << "dimension error\n";
        return Y;
    }
    int y0 = get_mat_dim(A, 0), y1 = get_mat_dim(B, 1);
    Y = zero_mat(y0, y1);
    VectorArray a_vecs = extract_vec(A, 0), b_vecs = extract_vec(B, 1);

    for (int i = 0; i < y0;i++){
        for (int j = 0; j < y1;j++){
            Y[i][j] = dproduct(a_vecs[i], b_vecs[j]);
        }
    }
    return Y;
}

int main(int argc, char* argv[]){
    if(argc != 3){
        std::cout << "wrong number of arguments\n";
        return EXIT_FAILURE;
    }
    std::string mat_a_fn = argv[1], mat_b_fn = argv[2];
    Matrix A = read_matrix_from_file(mat_a_fn);
    Matrix B = read_matrix_from_file(mat_b_fn);
    Matrix Y = multiply(A, B);
    std::cout << matrix_to_string(A) << std::endl;
    std::cout << "*" << std::endl << std::endl;
    std::cout << matrix_to_string(B) << std::endl;
    std::cout << "=" << std::endl << std::endl;
    std::cout << matrix_to_string(Y) << std::endl;
}