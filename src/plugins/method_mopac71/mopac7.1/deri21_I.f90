      MODULE deri21_I   
      INTERFACE
!...Generated by Pacific-Sierra Research 77to90  4.4G  10:47:06  03/09/06  
      SUBROUTINE deri21 (A, NVAR, MINEAR, NFIRST, VNERT, PNERT, B, NCUT) 
      USE vast_kind_param,ONLY: DOUBLE       
      INTEGER, INTENT(IN) :: NVAR 
      INTEGER, INTENT(IN) :: MINEAR 
      INTEGER, INTENT(IN) :: NFIRST 
      REAL(DOUBLE), DIMENSION(MINEAR,NVAR) :: A 
      REAL(DOUBLE), DIMENSION(NVAR), INTENT(INOUT) :: VNERT 
      REAL(DOUBLE), DIMENSION(NVAR), INTENT(INOUT) :: PNERT 
      REAL(DOUBLE), DIMENSION(MINEAR,*) :: B 
      INTEGER, INTENT(OUT) :: NCUT 
      END SUBROUTINE  
      END INTERFACE 
      END MODULE 
