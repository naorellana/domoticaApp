<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<jsp:include page="header.jsp" />
<jsp:include page="clima/cards.jsp" />
<jsp:include page="clima/graficaLineas.jsp" />
<jsp:include page="footer.jsp" />





<table class="table table-bordered table-striped table-hover table-responsive">
    <thead>
        <tr>
            <th>ID</th>
            <th>Nombre</th>
            <th>E-Mail</th>
            <th>Teléfono</th>
            <th>Tipo De Usuario</th>
            <th>Estado</th>
            <th>Acciones</th>
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


                <br><br>
                
                <table class="table table-bordered table-striped table-hover table-responsive">
                    <thead>
                        <tr>
                            <th>ID</th>
                            <th>Nombre</th>
                            <th>E-Mail</th>
                            <th>Teléfono</th>
                            <th>Tipo De Usuario</th>
                            <th>Estado</th>
                            <th>Acciones</th>
                        </tr>
                    </thead>
                    <tbody>
                        <c:forEach items="${datos}" var="dato">
                            <tr>
                                <td><c:out value="${dato.id}" /></td>
                                <td><c:out value="${dato.nombre}" /></td>
                                <td><c:out value="${dato.correo}" /></td>
                                <td><c:out value="${dato.telefono}" /></td>
                                <td><c:out value="${dato.rol}" /></td>
                                <td><c:out value="${dato.estado}" /></td>
                                <td>
                                    <a href="<c:url value="edit?id=${dato.id}" />">
                                        <span class="glyphicon glyphicon-pencil" aria-hidden="true"></span><button  type="button" class="btn btn-warning btn-sm">Editar</button></a>
                                    <a href="<c:url value="delete?id=${dato.id}" />">
                                        <span class="glyphicon glyphicon-trash" aria-hidden="true"></span><button  type="button" class="btn btn-danger btn-sm" onclick="myFunctionEli()">Eliminar</button></a>
                                    
                                    <a href="<c:url value="usuariodata?id=${dato.id}" />">
                                        <span class="glyphicon glyphicon-pencil" aria-hidden="true"></span><button  type="button" class="btn btn-primary btn-sm" onclick="myFunctionRepo()">Reporte</button></a>
                                    <a href="<c:url value="beta?codigo=2,${dato.id}" />">
                                        <span class="glyphicon glyphicon-trash" aria-hidden="true"></span><button  type="button" class="btn btn-dark btn-sm" onclick="myFunctionHuella()">Guardar Huella</button></a>
                                    <a href="<c:url value="facturaData?id=${dato.id}" />">
                                        <span class="glyphicon glyphicon-trash" aria-hidden="true"></span><button  type="button" class="btn btn-info btn-sm" onclick="myFunctionFac()">Factura</button></a>
                                    <a href="<c:url value="beta?codigo=3,${dato.id}" />">
                                        <span class="glyphicon glyphicon-trash" aria-hidden="true"></span><button  type="button" class="btn btn-success btn-sm" onclick="myFunctionEntrar()">Entrar</button></a>
                                    
                                </td>
                            </tr>
                        </c:forEach>
                    </tbody>
                </table>
