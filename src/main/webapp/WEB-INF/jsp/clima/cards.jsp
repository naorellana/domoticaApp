<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<div class="card-group">
    <div class="card text-center">
        <img width="200" height="200" class="card-img-top" src="https://image.flaticon.com/icons/svg/1113/1113779.svg" alt="Card image cap">
        <div class="card-body">
            <h2 class="card-title">Temperatura <span class="badge badge-danger">${s1} &degC</span></h2>
            <p class="card-text">Sensación Termica de su hogar monitoreada con Arduino.</p>
        </div>
        <div class="card-footer">
            <small class="text-muted">Ultima Actualización: <c:out value="${dato[0].fecha}" /></small>
        </div>
    </div>
    <div class="card text-center">
        <img class="card-img-top" width="200px" height="200px" src="https://image.flaticon.com/icons/svg/1113/1113760.svg"  alt="Card image cap">
        <div class="card-body">
            <h2 class="card-title">Humedad <span class="badge badge-primary">${s2} %</span></h2>
            <p class="card-text">Datos De Humedad relativa.</p>
        </div>
        <div class="card-footer">
            <small class="text-muted">Ultima Actualización: <c:out value="${dato[0].fecha}" /></small>
        </div>
    </div>
    <div class="card text-center">
        <!--<img class="card-img-top" width="200px" height="200em"  src="https://image.flaticon.com/icons/svg/1113/1113753.svg" alt="Card image cap">
        --><img class="card-img-top" width="200px" height="200em"  src="        https://image.flaticon.com/icons/svg/603/603494.svg" alt="Card image cap">
        <div class="card-body">
            <h2 class="card-title">Intensidad De Luz<span class="badge badge-warning">${s3} %</span></h2>
            <div class="progress">
  <div class="progress-bar progress-bar-striped progress-bar-animated  bg-warning" role="progressbar" aria-valuenow="" aria-valuemin="0" aria-valuemax="100" style="width: <c:out value="${dato[0].sesnor3}" />%"></div>
</div>
        </div>
        <div class="card-footer">
            <small class="text-muted">Ultima Actualización: <c:out value="${dato[0].fecha}" /></small>
        </div>
    </div>
</div>