<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<jsp:include page="header.jsp" />
        <div class="container-fluid">
            <div class="row">
                <h1>Administración de Usuarios</h1>
                <p>
                    <a href="<c:url value="new" />" class="btn btn-success"><span class="glyphicon glyphicon-plus" aria-hidden="true"></span> Agregar</a>
                </p>
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
            </div>
            
        </div>
<script>
function myFunction() {
    alert("Hello\nHow are you?");
}

function myFunctionEli() {
    alert("Procesando Solicitud De Borrado");
}

function myFunctionEntrar() {
    alert("Cuando El Lector de Huellas Digitales Encienda La Luz De Forma Intermitente \n Coloque Su Dedo Con La Huella Registrada");
}
function myFunctionHuella() {
    alert("INSTRUCCIONES: \n1- El Usuario Debe Colocar La Huella Cuando El Sensor Encienda La Luz\n Una Vez Colocada,\n 2- Retirar El Dedo Del Sensor \n 3-Colocar La huella Nuevamente Para Confirmar");
}
function myFunctionFact() {
    alert("Se Generará El Forulario Para La Factura Correspondiente");
}
function myFunctionRepo() {
    alert("Se Generará El Reporte Solicitado");
}
</script>
<jsp:include page="footer.jsp" />