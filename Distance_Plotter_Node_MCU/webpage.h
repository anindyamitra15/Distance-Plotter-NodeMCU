const char indexPage[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <script src="https://code.highcharts.com/highcharts.js"></script>
  <style>
    body {
      min-width: 310px;
      max-width: 800px;
      height: 400px;
      margin: 0 auto;
    }
    h2 {
      font-family: Arial;
      font-size: 2.5rem;
      text-align: center;
    }
  </style>
</head>
<body>
  <h2>ESP8266 Distance Plot</h2>
  <div id="chart-distance" class="container"></div>
</body>
<script>
var chart = new Highcharts.Chart({
  chart:{ renderTo : 'chart-distance' },
  title: { text: 'HC-SR04 Distance' },
  series: [{
    showInLegend: false,
    data: []
  }],
  plotOptions: {
    line: { animation: false,
      dataLabels: { enabled: true }
    },
    series: { color: '#059e8a' }
  },
  xAxis: { type: 'datetime',
    dateTimeLabelFormats: { second: '%H:%M:%S' }
  },
  yAxis: {
    title: { text: 'Distance (cm)' }
  },
  credits: { enabled: false }
});
setInterval(function ( ) {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      var x = (new Date()).getTime(),
          y = parseFloat(this.responseText);
      //console.log(this.responseText);
      if(chart.series[0].data.length > 40) {
        chart.series[0].addPoint([x, y], true, true, true);
      } else {
        chart.series[0].addPoint([x, y], true, false, true);
      }
    }
  };
  xhttp.open("GET", "/distance", true);
  xhttp.send();
}, 1000 ) ;
</script>
</html>
)rawliteral";
