<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<jsp:include page="../header.jsp" />
        <div class="container">
            <div class="row">
                <h1>Gestor De Usuarios</h1>
                <p>
                    <a href="<c:url value="UserNew" />" class="btn btn-success"><span class="glyphicon glyphicon-plus" aria-hidden="true"></span> Agregar</a>
                </p>
                <table class="table table-bordered table-striped table-hover table-responsive">
                    <thead>
                        <tr>
                            <th>USERNAME</th>
                            <th>Acciones</th>
                        </tr>
                    </thead>
                    <tbody>
                        <c:forEach items="${datos}" var="dato">
                            <tr>
                                <td><c:out value="${dato.USERNAME}" /></td>
                                <td>
                                    <a href="<c:url value="editUser?USERNAME=${dato.USERNAME}" />"><span class="glyphicon glyphicon-pencil" aria-hidden="true"></span><button  type="button" class="btn btn-warning">Editar</button></a>
                                    <a href="<c:url value="deleteUser?USERNAME=${dato.USERNAME}" />"><span class="glyphicon glyphicon-trash" aria-hidden="true"></span><button  type="button" class="btn btn-danger">Eliminar</button></a>
                                </td>
                            </tr>
                        </c:forEach>
                    </tbody>
                </table>
            </div>
            
        </div>
    </body>
</html>
<jsp:include page="../footer.jsp" />