<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<figure class="figure">
  <img src="https://image.flaticon.com/icons/svg/143/143786.svg" class="figure-img img-fluid rounded" alt="A generic square placeholder image with rounded corners in a figure.">
  <figcaption class="figure-caption">A caption for the above image.</figcaption>
</figure>

        <script type="text/javascript" src="jquery-1.12.0.min.js"></script>
        <script src="/js/jquery-3.3.1.min.js"></script>
        <script src="/js/Chart.bundle.min.js"></script>
        <script type="text/javascript">
            $(document).ready(function () {
                var datos = {
                    type: "polarArea",
                    data: {
                        datasets: [{
                                data: [
                                    100,
                                    100,
                                    100,
                                    100,
                                    100,
                                    100,
                                    100,
                                    100,
                                    100,
                                    100,
                                ]
                            },
                            {
                                data: [
                                    100,
                                    10,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    0,
                                    10,
                                ],
                                backgroundColor: [
                                    "#F7464A",
                                    "#46BFBD",
                                    "#FDB45C",
                                    "#949FB1",
                                    "#F7464A",
                                ],
                            }
                        ],
                        labels: [
                            "Datos 1",
                            "Datos 2",
                            "Datos 3",
                            "Datos 4",
                            "Datos 5",
                            "Datos 1",
                            "Datos 2",
                            "Datos 3",
                            "Datos 4",
                            "Datos 5",
                        ]
                    },
                    options: {
                        responsive: true,
                    }
                };

                var canvas = document.getElementById('chart').getContext('2d');
                window.pie = new Chart(canvas, datos);

                setInterval(function () {
                    datos.data.datasets.splice(1);
                    var newData = {
                        backgroundColor: [
                            "#F7464A",
                            "#46BFBD",
                            "#FDB45C",
                            "#949FB1",
                            "#4D5360",
                        ],
                        data: [getRandom(), 0, 0, 0, 0, 0, 0, 0, 0, 0]
                    };

                    datos.data.datasets.push(newData);

                    window.pie.update();

                }, 2000);



                function getRandom() {
                    return Math.round(Math.random() * 100);
                }


            });
        </script>
        <div id="canvas-container" class="col-10">
            <canvas id="chart" ></canvas>
        </div>
