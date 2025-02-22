#include "ns3/netanim-module.h"


./ns3 run scratch/test_senct.cc
java -jar tracemetrice.jar
./NetAnim 


set terminal pdf
set output "apple.pdf"
set title "apple"
set xlabel "From_Id_To_Id"
set ylabel "Tx"
plot "apple.txt" using 1:3 with lines title "BCT",\
"apple.txt" using 1:3 with linespoints title "anith eka"


set terminal pdf
set output "histogram.pdf"
set style data histogram
set style histogram clustered gap 1
set style fill solid border -1
set boxwidth 0.9
set title "City AQI Comparison"
set xlabel "City"
set ylabel "AQI"
set xtics rotate by -45
plot 'mydata.data' using 2:xtic(1) title "AQI Last Month", \
     '' using 3 title "AQI Current Month"




    pointToPoint.EnablePcapAll("apple_pcp_p2p");
    csma.EnablePcapAll("apple_pcp_csma");
    //csma.EnablePcap("second", csmaDevices.Get(1), true);

    AsciiTraceHelper ascii;
    pointToPoint.EnableAsciiAll(ascii.CreateFileStream("apple_java_p2p.tr"));
    csma.EnableAsciiAll(ascii.CreateFileStream("apple_java_csma.tr"));

    AnimationInterface anime ("apple_anime.xml");
    anime.SetConstantPosition(p2pNodes.Get(0),10.0,10.0);
    anime.SetConstantPosition(p2pNodes.Get(1),30.0,20.0);
    anime.SetConstantPosition(csmaNodes.Get(1),80.0,30.0);
    anime.SetConstantPosition(csmaNodes.Get(2),50.0,40.0);
    anime.SetConstantPosition(csmaNodes.Get(3),20.0,50.0);
