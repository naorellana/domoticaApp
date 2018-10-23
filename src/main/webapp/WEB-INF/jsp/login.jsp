<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<jsp:include page="header.jsp" />
 <div class="container text-center">
     <br><br>
    <h1>Iniciar Sesion</h1>
        <!-- Page Content goes here -->
        
        <div>
            <form action="/login" method='POST'> 
                <div class="form-group">
                    <label for="exampleInputEmail1">Usuario <span><i class="material-icons prefix">person</i></span></label>
                    <input type="text" class="form-control" id="exampleInputEmail1" name="username" aria-describedby="emailHelp" placeholder="Enter email">
                </div>
                <div class="form-group">
                    <label for="exampleInputPassword1">Password <span><i class="material-icons prefix">security</i></span></label>
                    <input type="password" class="form-control" name="password" id="exampleInputPassword1" placeholder="Password">
                </div>
                <button type="submit" class="btn btn-primary">Ingresar</button>
            </form>
        </div>
        
        <p><c:if test="${not empty errorMessge}"><div class="text-warning">${errorMessge}</div></c:if></p>
      </div>
 <jsp:include page="footer.jsp" />
