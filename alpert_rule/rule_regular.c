# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# include "alpert_rule.h"

/******************************************************************************/

void rule_regular ( int rule, int j, double x[], double w[] )

/******************************************************************************/
/*
  Purpose:

    RULE_REGULAR returns an Alpert rule for regular functions.

  Licensing:

    This code is distributed under the GNU LGPL license.

  Modified:

    04 December 2015

  Author:

    John Burkardt

  Reference:

    Bradley Alpert,
    Hybrid Gauss-Trapezoidal Quadrature Rules,
    SIAM Journal on Scientific Computing,
    Volume 20, Number 5, pages 1551-1584, 1999.

  Parameters:

    Input, int RULE, the index of the rule, between 1 and 12.

    Input, int J, the number of points in the rule.

    Output, double X[J], W[J], the points and weights for the rule.
*/
{
  double x01[1] = {
    1.666666666666667E-01 };
  double w01[1] = {
    5.000000000000000E-01 };
  double x02[2] = {
    2.000000000000000E-01,
    1.000000000000000E+00 };
  double w02[2] = {
    5.208333333333333E-01,
    9.791666666666667E-01 };
  double x03[2] = {
    2.245784979812614E-01,
    1.013719374359164E+00 };
  double w03[2] = {
    5.540781643606372E-01,
    9.459218356393628E-01 };
  double x04[3] = {
    2.250991042610971E-01,
    1.014269060987992E+00,
    2.000000000000000E+00 };
  double w04[3] = {
    5.549724327164180E-01,
    9.451317411845473E-01,
    9.998958260990347E-01 };
  double x05[3] = {
    2.180540672543505E-01,
    1.001181873031216E+00,
    1.997580526418033E+00 };
  double w05[3] = {
    5.408088967208193E-01,
    9.516615045823566E-01,
    1.007529598696824E+00 };
  double x06[4] = {
    2.087647422032129E-01,
    9.786087373714483E-01,
    1.989541386579751E+00,
    3.000000000000000E+00 };
  double w06[4] = {
    5.207988277246498E-01,
    9.535038018555888E-01,
    1.024871626402471E+00,
    1.000825744017291E+00 };
  double x07[6] = {
    7.023955461621939E-02,
    4.312297857227970E-01,
    1.117752734518115E+00,
    2.017343724572518E+00,
    3.000837842847590E+00,
    4.000000000000000E+00 };
  double w07[6] = {
    1.922315977843698E-01,
    5.348399530514687E-01,
    8.170209442488760E-01,
    9.592111521445966E-01,
    9.967143408044999E-01,
    9.999820119661890E-01 };
  double x08[8] = {
    9.919337841451028E-02,
    5.076592669645529E-01,
    1.184972925827278E+00,
    2.047493467134072E+00,
    3.007168911869310E+00,
    4.000474996776184E+00,
    5.000007879022339E+00,
    6.000000000000000E+00 };
  double w08[8] = {
    2.528198928766921E-01,
    5.550158230159486E-01,
    7.852321453615224E-01,
    9.245915673876714E-01,
    9.839350200445296E-01,
    9.984463448413151E-01,
    9.999592378464547E-01,
    9.999999686258662E-01 };
  double x09[10] = {
    9.209200446233291E-02,
    4.752021947758861E-01,
    1.124687945844539E+00,
    1.977387385642367E+00,
    2.953848957822108E+00,
    3.976136786048776E+00,
    4.994354281979877E+00,
    5.999469539335291E+00,
    6.999986704874333E+00,
    8.000000000000000E+00 };
  double w09[10] = {
    2.351836144643984E-01,
    5.248820509085946E-01,
    7.634026409869887E-01,
    9.284711336658351E-01,
    1.010969886587741E+00,
    1.024959725311073E+00,
    1.010517534639652E+00,
    1.001551595797932E+00,
    1.000061681794188E+00,
    1.000000135843597E+00 };
  double x10[12] = {
    6.001064731474805E-02,
    3.149685016229433E-01,
    7.664508240518316E-01,
    1.396685781342510E+00,
    2.175195903206602E+00,
    3.062320575880355E+00,
    4.016440988792476E+00,
    5.002872064275734E+00,
    6.000285453310164E+00,
    7.000012964962529E+00,
    8.000000175554469E+00,
    9.000000000000000E+00 };
  double w10[12] = {
    1.538932104518340E-01,
    3.551058128559424E-01,
    5.449200036280007E-01,
    7.104078497715549E-01,
    8.398780940253654E-01,
    9.272767950890611E-01,
    9.750605697371132E-01,
    9.942629650823470E-01,
    9.992421778421898E-01,
    9.999534370786161E-01,
    9.999990854912925E-01,
    9.999999989466828E-01 };
  double x11[14] = {
    6.234360533194102E-02,
    3.250286721702614E-01,
    7.837350794282182E-01,
    1.415673112616924E+00,
    2.189894250061313E+00,
    3.070053877483040E+00,
    4.018613756218047E+00,
    5.002705902035397E+00,
    5.999929741810400E+00,
    6.999904720846024E+00,
    7.999986894843540E+00,
    8.999999373380393E+00,
    9.999999992002911E+00,
    1.100000000000000E+01 };
  double w11[14] = {
    1.595975279734157E-01,
    3.637046028193864E-01,
    5.498753177297441E-01,
    7.087986792086956E-01,
    8.335172275501195E-01,
    9.204446510608518E-01,
    9.710881776552090E-01,
    9.933296578555239E-01,
    9.994759087910050E-01,
    1.000133030254421E+00,
    1.000032915011460E+00,
    1.000002261653775E+00,
    1.000000042393520E+00,
    1.000000000042872E+00 };
  double x12[16] = {
    5.899550614325259E-02,
    3.082757062227814E-01,
    7.463707253079130E-01,
    1.355993726494664E+00,
    2.112943217346336E+00,
    2.987241496545946E+00,
    3.944798920961176E+00,
    4.950269202842798E+00,
    5.972123043117706E+00,
    6.989783558137742E+00,
    7.997673019512965E+00,
    8.999694932747039E+00,
    9.999979225211805E+00,
    1.099999938266130E+01,
    1.199999999462073E+01,
    1.300000000000000E+01 };
  double w12[16] = {
    1.511076023874179E-01,
    3.459395921169090E-01,
    5.273502805146873E-01,
    6.878444094543021E-01,
    8.210319140034114E-01,
    9.218382875515803E-01,
    9.873027487553060E-01,
    1.018251913441155E+00,
    1.021933430349293E+00,
    1.012567983413513E+00,
    1.004052289554521E+00,
    1.000713413344501E+00,
    1.000063618302950E+00,
    1.000002486385216E+00,
    1.000000030404477E+00,
    1.000000000020760E+00 };

  if ( rule < 1 || 12 < rule )
  {
    fprintf ( stderr, "\n" );
    fprintf ( stderr, "RULE_REGULAR - Fatal error!\n" );
    fprintf ( stderr, "  Input value of RULE is not between 1 and 12.\n" );
    exit ( 1 );
  }

  if ( rule == 1 )
  {
    r8vec_copy ( j, x01, x );
    r8vec_copy ( j, w01, w );
  }
  else if ( rule == 2 )
  {
    r8vec_copy ( j, x02, x );
    r8vec_copy ( j, w02, w );
  }
  else if ( rule == 3 )
  {
    r8vec_copy ( j, x03, x );
    r8vec_copy ( j, w03, w );
  }
  else if ( rule == 4 )
  {
    r8vec_copy ( j, x04, x );
    r8vec_copy ( j, w04, w );
  }
  else if ( rule == 5 )
  {
    r8vec_copy ( j, x05, x );
    r8vec_copy ( j, w05, w );
  }
  else if ( rule == 6 )
  {
    r8vec_copy ( j, x06, x );
    r8vec_copy ( j, w06, w );
  }
  else if ( rule == 7 )
  {
    r8vec_copy ( j, x07, x );
    r8vec_copy ( j, w07, w );
  }
  else if ( rule == 8 )
  {
    r8vec_copy ( j, x08, x );
    r8vec_copy ( j, w08, w );
  }
  else if ( rule == 9 )
  {
    r8vec_copy ( j, x09, x );
    r8vec_copy ( j, w09, w );
  }
  else if ( rule == 10 )
  {
    r8vec_copy ( j, x10, x );
    r8vec_copy ( j, w10, w );
  }
  else if ( rule == 11 )
  {
    r8vec_copy ( j, x11, x );
    r8vec_copy ( j, w11, w );
  }
  else if ( rule == 12 )
  {
    r8vec_copy ( j, x12, x );
    r8vec_copy ( j, w12, w );
  }

  return;
}

