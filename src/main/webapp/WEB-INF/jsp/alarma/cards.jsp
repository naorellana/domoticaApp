<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<div class="card-group">
    <div class="card text-center">
        <img width="200" height="200" class="card-img-top" src="https://image.flaticon.com/icons/svg/1209/1209545.svg" alt="Card image cap">
        <div class="card-body">
            <h2 class="card-title">Sistema De Alarma </h2>
            <p class="card-text">Control De Alarma Remota.</p>
            <a href="/alarmActive" ><button type="button" class="btn btn-outline-success">
                    <i class="material-icons">power_off</i> <span>Activar</span>
                </button>
            </a>
            <a href="/alarmInactive"><button type="button" class="btn btn-outline-danger">
                    <i class="material-icons">power_off</i> <span>Apagar</span>
                </button>
            </a>
        </div>
        <div class="card-footer">
            <small class="text-muted">Last updated 3 mins ago</small>
        </div>
    </div>
    
    
</div>