<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<div class="card-group">
    <div class="card text-center">
        <div class="card-body col-12">
            <h2 class="card-title">Temperatura <span class="badge badge-danger">${s1} &degC</span></h2>
            <p class="card-text">Sensación Termica de su hogar monitoreada con Arduino.</p>
            <div class="table-responsive">
                <table class="table table-bordered table-striped table-hover ">
                    <thead class="thead-dark">
                    <tr>
                        <th>Registro</th>
                        <th>Temperatura</th>
                        <th>Humedad</th>
                        <th>Otro</th>
                        <th>Fecha</th>
                        <th>Comentarios</th>
                    </tr>
                </thead>
                <tbody>
                    <c:forEach items="${dato}" var="dat">
                        <tr>
                            <td><c:out value="${dat.registro}" /></td>
                            <td><c:out value="${dat.sensor1}" /></td>
                            <td><c:out value="${dat.sensor2}" /></td>
                            <td><c:out value="${dat.sesnor3}" /></td>
                            <td><c:out value="${dat.fecha}" /></td>
                            <td><c:out value="${dat.comentario}" /></td>
                        </tr>
                    </c:forEach>
                </tbody>
            </table>
            </div>
        </div>
        <div class="card-footer">
            <small class="text-muted">Ultima Actualización: <c:out value="${dato[0].fecha}" /></small>
        </div>
    </div>
</div>
            
        