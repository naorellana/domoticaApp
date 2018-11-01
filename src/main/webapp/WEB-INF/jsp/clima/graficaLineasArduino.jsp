<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<script type="text/javascript" src="jquery-1.12.0.min.js"></script>
<script src="/js/jquery-3.3.1.min.js"></script>
<script src="/js/Chart.bundle.min.js"></script>
<script type="text/javascript">
        $(document).ready(function(){
		
                var datos = {
                        labels : ["<c:out value="${dato[0].fecha}" />", "<c:out value="${dato[1].fecha}" />", "<c:out value="${dato[2].fecha}" />", 
                    "<c:out value="${dato[3].fecha}" />", "<c:out value="${dato[4].fecha}" />", "<c:out value="${dato[5].fecha}" />", 
                    "<c:out value="${dato[6].fecha}" />"],
            datasets: [{
                    label: "Temperatura",            
                    backgroundColor: "rgba(50,50,215,0.5)",
                    data: [4, 12, 9, 7, 5,6,7]
                },
                {

                    label: "Humedad ",
                    backgroundColor: "rgba(244,5,18,0.5)",
        
                    data: [10, 7, 30, 6, 5,20,]
                },
                {
                    label: "Presión, X100",
                    backgroundColor: "rgba(220,220,220,0.5)",
                    data: [9, 6, 15, 6, 17, 12,18]
                }
            ]
        };


        var canvas = document.getElementById('chart').getContext('2d');
        window.bar = new Chart(canvas, {
            type: "line",
            data: datos,
            options: {
                elements: {
                    rectangle: {
                        borderWidth: 1,
                        borderColor: "rgb(0,255,0)",
                        borderSkipped: 'bottom'
                    }
                },
                responsive: true,
                title: {
                    display: true,
                    text: "Ultimos 7 Registros"
                }
            }
        });

        setInterval(function () {
            var newData = [
                [<c:out value="${dato[0].sensor1}" />, <c:out value="${dato[1].sensor1}" />, <c:out value="${dato[2].sensor1}" />, 
                    <c:out value="${dato[3].sensor1}" />, <c:out value="${dato[4].sensor1}" />, <c:out value="${dato[5].sensor1}" />, 
                    <c:out value="${dato[6].sensor1}" />],
                [<c:out value="${dato[0].sensor2}" />, <c:out value="${dato[1].sensor2}" />, <c:out value="${dato[2].sensor2}" />, 
                    <c:out value="${dato[3].sensor2}" />, <c:out value="${dato[4].sensor2}" />, <c:out value="${dato[5].sensor2}" />, 
                    <c:out value="${dato[6].sensor2}" />],                
                [<c:out value="${dato[0].sesnor3}" />, <c:out value="${dato[1].sesnor3}" />, <c:out value="${dato[2].sesnor3}" />, 
                    <c:out value="${dato[3].sesnor3}" />, <c:out value="${dato[4].sesnor3}" />, <c:out value="${dato[5].sesnor3}" />, 
                    <c:out value="${dato[6].sesnor3}" />],
                
                
        ];

            $.each(datos.datasets, function (i, dataset) {
                dataset.data = newData[i];
            });
            window.bar.update();
        }, 1000);




        function getRandom() {
            return Math.round(Math.random() * 100);
        }


    });
</script>
    <div id="canvas-container" style="width:100%; height: 100%"  class="col-sm-12 col-md-12 text-center">
        <canvas id="chart" width="500" height="100%"></canvas>
    </div>