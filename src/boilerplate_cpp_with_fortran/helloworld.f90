! src/helloworld.f90
module fortran_module
    use, intrinsic :: iso_c_binding
    implicit none
contains

    subroutine fortran_hello() bind(c, name="fortran_hello")
        use iso_fortran_env, only: output_unit
        write(output_unit, '(A)') "Olá do Fortran 2018!"
    end subroutine fortran_hello

    subroutine fortran_hello_name(name) bind(c, name="fortran_hello_name")
        use, intrinsic :: iso_c_binding, only: c_char, c_null_char
        character(kind=c_char), intent(in) :: name(*)
        character(len=100) :: fortran_name
        integer :: i, length

        length = 0
        do i = 1, 100
            if (name(i) == c_null_char) exit
            length = length + 1
        end do
        fortran_name = transfer(name(1:length), fortran_name)

        write(*,'(A,A,A)') "Olá, ", trim(fortran_name), "! Do Fortran!"
    end subroutine fortran_hello_name

    function fortran_add(a, b) result(c) bind(c, name="fortran_add")
        use, intrinsic :: iso_c_binding, only: c_int
        integer(c_int), intent(in), value :: a, b
        integer(c_int) :: c
        c = a + b
        write(*,'(A,I0,A,I0,A,I0)') "Fortran calculou: ", a, " + ", b, " = ", c
    end function fortran_add

end module fortran_module
