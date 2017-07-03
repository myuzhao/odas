#ifndef __ODAS_SIGNAL_MATRIX
#define __ODAS_SIGNAL_MATRIX

    #include <stdlib.h>
    #include <stdio.h>

    //! Matrix
    typedef struct matrix_obj {

        float ** array;                         ///< Array of elements in the matrix.
        unsigned int nRows;                     ///< Number of rows.
        unsigned int nCols;                     ///< Number of columns.

    } matrix_obj;

    /** Constructor. Initialize all elements to zero in a matrix nRows x nCols.
        \param      nRows           Number of rows.
        \param      nCols           Number of columns.
        \return                     Pointer to the instantiated object.
    */  
    matrix_obj * matrix_construct_zero(const unsigned int nRows, const unsigned int nCols);

    /** Constructor. Clone the object.
        \param      matrix          Object to be cloned.
        \return                     Pointer to the instantiated object.
    */  
    matrix_obj * matrix_construct_matrix(const matrix_obj * matrix);

    /** Set elements to 0.
        \param      obj             Object to be used.
    */
    void matrix_copy_zero(matrix_obj * obj);

    /** Set fields to the field values of the model object. No memory allocated.
        \param      matrix          Object to be copied.
        \param      obj             Object to be modified.
    */  
    void matrix_copy_matrix(matrix_obj * obj, const matrix_obj * matrix);

    /** Destructor. Free memory.
        \param      obj             Object to be destroyed.
    */
    void matrix_destroy(matrix_obj * obj);

    /** Compute the matrix transpose.
        \param      src             Matrix to be transpose.
        \param      obj             Transposed matrix.
    */
    void matrix_transpose(matrix_obj * obj, const matrix_obj * src);

    /** Add two matrices.
        \param      src1            First matrix to be added.
        \param      src2            Second matrix to be added.
        \param      obj             Result of the addition.
    */
    void matrix_add(matrix_obj * obj, const matrix_obj * src1, const matrix_obj * src2);

    /** Subtract two matrices.
        \param      src1            Matrix to be subtracted from.
        \param      src2            Matrix to subtract.
        \param      obj             Result of the subtraction.
    */
    void matrix_sub(matrix_obj * obj, const matrix_obj * src1, const matrix_obj * src2);

    /** Multiply two matrices.
        \param      src1            First matrix to be multiplied.
        \param      src2            Second matrix to be multiplied.
        \param      obj             Result of the multiplication.
    */
    void matrix_mul(matrix_obj * obj, const matrix_obj * src1, const matrix_obj * src2);

    /** Inverse a matrix.
        \param      src             Matrix to be inverted.
        \param      obj             Inverted matrix.
    */
    void matrix_inv(matrix_obj * obj, const matrix_obj * src);

    /** Compute the determinant.
        \param      obj             Matrix which determinant is computed.
        \return                     Determinant value.
    */
    float matrix_det(const matrix_obj * obj);

    /** Multiply a matrix by a scalar.
        \param      src             Matrix to be scaled.
        \param      scale           Scaling factor.
        \param      obj             Scaled matrix.
    */
    void matrix_scale(matrix_obj * obj, const matrix_obj * src, const float scale);

    /** Print the content of the matrix.
        \param      obj         Object to be used.
    */
    void matrix_printf(const matrix_obj * obj);

#endif