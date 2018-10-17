<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<div class="card-group">
    <div class="card text-center">
        <img width="200" height="200" class="card-img-top" src="https://image.flaticon.com/icons/svg/1113/1113779.svg" alt="Card image cap">
        <div class="card-body">
            <h2 class="card-title">Temperatura <span class="badge badge-danger">${valor} &degC</span></h2>
            <p class="card-text">Sensación Termica de su hogar monitoreada con Arduino.</p>
        </div>
        <div class="card-footer">
            <small class="text-muted">Last updated 3 mins ago</small>
        </div>
    </div>
    <div class="card text-center">
        <img class="card-img-top" width="200px" height="200px" src="https://image.flaticon.com/icons/svg/1113/1113760.svg"  alt="Card image cap">
        <div class="card-body">
            <h2 class="card-title">Humedad <span class="badge badge-primary">${valor} %</span></h2>
            <p class="card-text">Datos De Humedad relativa.</p>
        </div>
        <div class="card-footer">
            <small class="text-muted">Last updated 3 mins ago</small>
        </div>
    </div>
    <div class="card text-center">
        <img class="card-img-top" width="200px" height="200em"  src="https://image.flaticon.com/icons/svg/1113/1113753.svg" alt="Card image cap">
        <div class="card-body">
            <h2 class="card-title">Presión Atmosférica<span class="badge badge-secondary">${valor} hPa</span></h2>
            <p class="card-text">Datos De Presión atmosférica: .</p>
        </div>
        <div class="card-footer">
            <small class="text-muted">Last updated 3 mins ago</small>
        </div>
    </div>
</div>